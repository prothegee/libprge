#include "cryptography.hh"

void CCryptography::_bind_methods()
{
    // hash
    {
        ClassDB::bind_method(D_METHOD("sha1", "input"), &CCryptography::sha1);
        ClassDB::bind_method(D_METHOD("sha224", "input"), &CCryptography::sha224);
        ClassDB::bind_method(D_METHOD("sha256", "input"), &CCryptography::sha256);
        ClassDB::bind_method(D_METHOD("sha384", "input"), &CCryptography::sha384);
        ClassDB::bind_method(D_METHOD("sha512", "input"), &CCryptography::sha512);

        ClassDB::bind_method(D_METHOD("scrypt", "input"), &CCryptography::scrypt);

        ClassDB::bind_method(D_METHOD("aesEncrypt", "input", "iv", "ik"), &CCryptography::aesEncrypt);
        ClassDB::bind_method(D_METHOD("aesDecrypt", "input", "iv", "ik"), &CCryptography::aesDecrypt);

        ClassDB::bind_method(D_METHOD("xChaCha20encrypt", "input", "iv", "ik"), &CCryptography::xChaCha20encrypt);
        ClassDB::bind_method(D_METHOD("xChaCha20decrypt", "input", "iv", "ik"), &CCryptography::xChaCha20decrypt);

        ClassDB::bind_method(D_METHOD("rc6encrypt", "input", "iv", "ik"), &CCryptography::rc6encrypt);
        ClassDB::bind_method(D_METHOD("rc6decrypt", "input", "iv", "ik"), &CCryptography::rc6decrypt);
    }

    // streamCipher
    {
    }
}

CCryptography::CCryptography()
{
}

CCryptography::~CCryptography()
{
}

String CCryptography::sha1(const String input)
{
    return String(cryptographyFunctions::hash::sha1(input.ascii().get_data()).c_str());
}

String CCryptography::sha224(const String input)
{
    return String(cryptographyFunctions::hash::sha224(input.ascii().get_data()).c_str());
}

String CCryptography::sha256(const String input)
{
    return String(cryptographyFunctions::hash::sha256(input.ascii().get_data()).c_str());
}

String CCryptography::sha384(const String input)
{
    return String(cryptographyFunctions::hash::sha384(input.ascii().get_data()).c_str());
}

String CCryptography::sha512(const String input)
{
    return String(cryptographyFunctions::hash::sha512(input.ascii().get_data()).c_str());
}

String CCryptography::scrypt(const String input, const String salt, const ui64 computationCost, const ui64 blockSizeCost, const CryptoPP::word64 threadsCost, const ui32 derivedLength)
{
    return String(cryptographyFunctions::hash::scrypt(
        input.ascii().get_data(),
        salt.ascii().get_data(),
        static_cast<CryptoPP::word64>(computationCost),
        static_cast<CryptoPP::word64>(blockSizeCost),
        static_cast<CryptoPP::word64>(threadsCost),
        derivedLength).c_str()
    );
}

String CCryptography::aesEncrypt(const String input, const String iv, const String ik)
{
    return String(cryptographyFunctions::streamCipher::aesEncrypt(input.ascii().get_data(), iv.ascii().get_data(), ik.ascii().get_data()).c_str());
}

String CCryptography::aesDecrypt(const String input, const String iv, const String ik)
{
    return String(cryptographyFunctions::streamCipher::aesDecrypt(input.ascii().get_data(), iv.ascii().get_data(), ik.ascii().get_data()).c_str());
}

String CCryptography::xChaCha20encrypt(const String input, const String iv, const String ik)
{
    return String(cryptographyFunctions::streamCipher::xChaCha20encrypt(input.ascii().get_data(), iv.ascii().get_data(), ik.ascii().get_data()).c_str());
}

String CCryptography::xChaCha20decrypt(const String input, const String iv, const String ik)
{
    return String(cryptographyFunctions::streamCipher::xChaCha20decrypt(input.ascii().get_data(), iv.ascii().get_data(), ik.ascii().get_data()).c_str());
}

String CCryptography::rc6encrypt(const String input, const String iv, const String ik)
{
    return String(cryptographyFunctions::streamCipher::rc6encrypt(input.ascii().get_data(), iv.ascii().get_data(), ik.ascii().get_data()).c_str());
}

String CCryptography::rc6decrypt(const String input, const String iv, const String ik)
{
    return String(cryptographyFunctions::streamCipher::rc6decrypt(input.ascii().get_data(), iv.ascii().get_data(), ik.ascii().get_data()).c_str());
}
