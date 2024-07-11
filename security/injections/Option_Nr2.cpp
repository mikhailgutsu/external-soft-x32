#include <windows.h>
#include <wincrypt.h>
#include <string>

bool VerifyFileIntegrity(const std::string& filePath, const BYTE* expectedHash, DWORD hashSize) {
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    BYTE buffer[1024];
    DWORD bytesRead = 0;
    HANDLE hFile = CreateFileA(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);

    if (hFile == INVALID_HANDLE_VALUE) return false;
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) return false;
    if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash)) return false;

    while (ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
        if (!CryptHashData(hHash, buffer, bytesRead, 0)) return false;
    }

    BYTE hash[16];
    DWORD hashSizeActual = sizeof(hash);
    if (!CryptGetHashParam(hHash, HP_HASHVAL, hash, &hashSizeActual, 0)) return false;

    bool result = memcmp(hash, expectedHash, hashSize) == 0;

    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
    CloseHandle(hFile);

    return result;
}
