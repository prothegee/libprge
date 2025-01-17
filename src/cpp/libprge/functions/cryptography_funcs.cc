#include "cryptography_funcs.hh"

namespace libprge
{
namespace cryptographyFunctions
{

namespace hash
{
    std::string sha1(const std::string &input, const ECryptographyMode &mode)
    {
        std::string result;

        switch (mode)
        {
            #if LIBPRGE_USING_CRYPTOPP_CMAKE
            case CRYPTOGRAPHY_MODE_CRYPTOPP:
            {
                CryptoPP::SHA1 hash;
                CryptoPP::byte digest[CryptoPP::SHA1::DIGESTSIZE];
                CryptoPP::HexEncoder encoder;

                hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

                encoder.Attach(new CryptoPP::StringSink(result));
                encoder.Put(digest, sizeof(digest));
                encoder.MessageEnd();
            }
            break;
            #endif // LIBPRGE_USING_CRYPTOPP_CMAKE

            default:
            {
                result = "sha1 mode not supported";
                std::cerr << "ERROR: \"libprge::cryptographyFunctions::hash::sha1\":\n" << result << '\n';
            }
            break;
        }

        return result;
    }

    std::string sha224(const std::string &input, const ECryptographyMode &mode)
    {
        std::string result;

        switch (mode)
        {
            #if LIBPRGE_USING_CRYPTOPP_CMAKE
            case CRYPTOGRAPHY_MODE_CRYPTOPP:
            {
                CryptoPP::SHA224 hash;
                CryptoPP::byte digest[CryptoPP::SHA224::DIGESTSIZE];
                CryptoPP::HexEncoder encoder;

                hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

                encoder.Attach(new CryptoPP::StringSink(result));
                encoder.Put(digest, sizeof(digest));
                encoder.MessageEnd();
            }
            break;
            #endif // LIBPRGE_USING_CRYPTOPP_CMAKE

            default:
            {
                result = "sha224 mode not supported";
                std::cerr << "ERROR: \"libprge::cryptographyFunctions::hash::sha224\":\n" << result << '\n';
            }
            break;
        }

        return result;
    }

    std::string sha256(const std::string &input, const ECryptographyMode &mode)
    {
        std::string result;

        switch (mode)
        {
            #if LIBPRGE_USING_CRYPTOPP_CMAKE
            case CRYPTOGRAPHY_MODE_CRYPTOPP:
            {
                CryptoPP::SHA256 hash;
                CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];
                CryptoPP::HexEncoder encoder;

                hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

                encoder.Attach(new CryptoPP::StringSink(result));
                encoder.Put(digest, sizeof(digest));
                encoder.MessageEnd();
            }
            break;
            #endif // LIBPRGE_USING_CRYPTOPP_CMAKE

            default:
            {
                result = "sha256 mode not supported";
                std::cerr << "ERROR: \"libprge::cryptographyFunctions::hash::sha256\":\n" << result << '\n';
            }
            break;
        }

        return result;
    }

    std::string sha384(const std::string &input, const ECryptographyMode &mode)
    {
        std::string result;

        switch (mode)
        {
            #if LIBPRGE_USING_CRYPTOPP_CMAKE
            case CRYPTOGRAPHY_MODE_CRYPTOPP:
            {
                CryptoPP::SHA384 hash;
                CryptoPP::byte digest[CryptoPP::SHA384::DIGESTSIZE];
                CryptoPP::HexEncoder encoder;

                hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

                encoder.Attach(new CryptoPP::StringSink(result));
                encoder.Put(digest, sizeof(digest));
                encoder.MessageEnd();
            }
            break;
            #endif // LIBPRGE_USING_CRYPTOPP_CMAKE

            default:
            {
                result = "sha384 mode not supported";
                std::cerr << "ERROR: \"libprge::cryptographyFunctions::hash::sha384\":\n" << result << '\n';
            }
            break;
        }

        return result;
    }

    std::string sha512(const std::string &input, const ECryptographyMode &mode)
    {
        std::string result;

        switch (mode)
        {
            #if LIBPRGE_USING_CRYPTOPP_CMAKE
            case CRYPTOGRAPHY_MODE_CRYPTOPP:
            {
                CryptoPP::SHA512 hash;
                CryptoPP::byte digest[CryptoPP::SHA512::DIGESTSIZE];
                CryptoPP::HexEncoder encoder;

                hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

                encoder.Attach(new CryptoPP::StringSink(result));
                encoder.Put(digest, sizeof(digest));
                encoder.MessageEnd();
            }
            break;
            #endif // LIBPRGE_USING_CRYPTOPP_CMAKE

            default:
            {
                result = "sha512 mode not supported";
                std::cerr << "ERROR: \"libprge::cryptographyFunctions::hash::sha512\":\n" << result << '\n';
            }
            break;
        }

        return result;
    }

    #if LIBPRGE_USING_CRYPTOPP_CMAKE
    std::string scrypt(const std::string &input, const std::string &salt, const CryptoPP::word64 &computationCost, const CryptoPP::word64 &blockSizeCost, const CryptoPP::word64 &threadsCost, const uint32_t &derivedLength)
    {
        std::string result;

        std::string passwd_input(input), salt_input(salt);

        try
        {
            CryptoPP::SecByteBlock derived(derivedLength);

            CryptoPP::Scrypt scrypt;

            CryptoPP::AlgorithmParameters params = 
                CryptoPP::MakeParameters("Cost", computationCost)
                ("BlockSize", blockSizeCost)("Parallelization", threadsCost)
                ("Salt", CryptoPP::ConstByteArrayParameter(
                    (const CryptoPP::byte*)&salt_input[0], salt_input.size()));

            scrypt.DeriveKey(derived, derived.size(),
                (const CryptoPP::byte*)&passwd_input[0], passwd_input.size(), params);

            CryptoPP::StringSource(derived, derived.size(), true,
                new CryptoPP::HexEncoder(new CryptoPP::StringSink(result)));
        }
        catch(const CryptoPP::Exception &e)
        {
            std::cerr << "ERROR: \"libprge::cryptographyFunctions::hash::scrypt\":\n" << e.what() << '\n';
        }

        return result;
    }
    #endif // LIBPRGE_USING_CRYPTOPP_CMAKE
} // namespace hash

namespace streamCipher
{
    #if LIBPRGE_USING_CRYPTOPP_CMAKE
    std::string aesEncrypt(const std::string &input, const std::string &iv, const std::string &ik)
    {
        std::string tmp, result;

        try
        {
            const size_t ivLength = iv.size();
            const size_t keyLength = ik.size();

            CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption enc;
            enc.SetKeyWithIV((const CryptoPP::byte*)ik.data(), keyLength, (const CryptoPP::byte*)iv.data(), ivLength);

            CryptoPP::StringSource(input, true, new CryptoPP::StreamTransformationFilter(enc, new CryptoPP::StringSink(tmp)));

            CryptoPP::StringSource(tmp, true, new CryptoPP::HexEncoder(new CryptoPP::StringSink(result)));
        }
        catch(const CryptoPP::Exception& e)
        {
            std::cerr << "ERROR: \"libprge::cryptographyFunctions::streamCipher::aesEncrypt\":\n" << e.what() << '\n';
        }

        return result;
    }

    std::string aesDecrypt(const std::string &input, const std::string &iv, const std::string &ik)
    {
        std::string tmp, result;

        try
        {
            const size_t ivLength = iv.size();
            const size_t keyLength = ik.size();

            CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption dec;
            dec.SetKeyWithIV((const CryptoPP::byte*)ik.data(), keyLength, (const CryptoPP::byte*)iv.data(), ivLength);

            CryptoPP::StringSource(input, true, new CryptoPP::HexDecoder(new CryptoPP::StringSink(tmp)));

            CryptoPP::StringSource ssrc(tmp, true, new CryptoPP::StreamTransformationFilter(dec, new CryptoPP::StringSink(result)));
        }
        catch(const CryptoPP::Exception& e)
        {
            std::cerr << "ERROR: \"libprge::cryptographyFunctions::streamCipher::aesDecrypt\":\n" << e.what() << '\n';
        }

        return result;
    }

    std::string xChaCha20encrypt(const std::string &input, const std::string &iv, const std::string &ik)
    {
        std::string tmp, result;

        try
        {
            const size_t ivLength = iv.size();
            const size_t keyLength = ik.size();

            CryptoPP::XChaCha20::Encryption enc;
            enc.SetKeyWithIV((const CryptoPP::byte*)ik.data(), keyLength, (const CryptoPP::byte*)iv.data(), ivLength);

            CryptoPP::StringSource(input, true, new CryptoPP::StreamTransformationFilter(enc, new CryptoPP::StringSink(tmp)));

            CryptoPP::StringSource(tmp, true, new CryptoPP::HexEncoder(new CryptoPP::StringSink(result)));
        }
        catch(const CryptoPP::Exception& e)
        {
            std::cerr << "ERROR: \"libprge::cryptographyFunctions::streamCipher::xChaCha20encrypt\":\n" << e.what() << '\n';
        }

        return result;
    }

    std::string xChaCha20decrypt(const std::string &input, const std::string &iv, const std::string &ik)
    {
        std::string tmp, result;

        try
        {
            const size_t ivLength = iv.size();
            const size_t keyLength = ik.size();

            CryptoPP::XChaCha20::Decryption dec;
            dec.SetKeyWithIV((const CryptoPP::byte*)ik.data(), keyLength, (const CryptoPP::byte*)iv.data(), ivLength);

            CryptoPP::StringSource(input, true, new CryptoPP::HexDecoder(new CryptoPP::StringSink(tmp)));

            CryptoPP::StringSource ssrc(tmp, true, new CryptoPP::StreamTransformationFilter(dec, new CryptoPP::StringSink(result)));
        }
        catch(const CryptoPP::Exception& e)
        {
            std::cerr << "ERROR: \"libprge::cryptographyFunctions::streamCipher::xChaCha20decrypt\":\n" << e.what() << '\n';
        }

        return result;
    }

    std::string rc6encrypt(const std::string &input, const std::string &iv, const std::string &ik)
    {
        std::string tmp, result;

        try
        {
            const size_t ivLength = iv.size();
            const size_t keyLength = ik.size();

            CryptoPP::CBC_Mode<CryptoPP::RC6>::Encryption enc;
            enc.SetKeyWithIV((const CryptoPP::byte*)ik.data(), keyLength, (const CryptoPP::byte*)iv.data(), ivLength);

            CryptoPP::StringSource(input, true, new CryptoPP::StreamTransformationFilter(enc, new CryptoPP::StringSink(tmp)));

            CryptoPP::StringSource(tmp, true, new CryptoPP::HexEncoder(new CryptoPP::StringSink(result)));
        }
        catch(const CryptoPP::Exception& e)
        {
            std::cerr << "ERROR: \"libprge::cryptographyFunctions::streamCipher::rc6encrypt\":\n" << e.what() << '\n';
        }

        return result;
    }

    std::string rc6decrypt(const std::string &input, const std::string &iv, const std::string &ik)
    {
        std::string tmp, result;

        try
        {
            const size_t ivLength = iv.size();
            const size_t keyLength = ik.size();

            CryptoPP::CBC_Mode<CryptoPP::RC6>::Decryption dec;
            dec.SetKeyWithIV((const CryptoPP::byte*)ik.data(), keyLength, (const CryptoPP::byte*)iv.data(), ivLength);

            CryptoPP::StringSource(input, true, new CryptoPP::HexDecoder(new CryptoPP::StringSink(tmp)));

            CryptoPP::StringSource ssrc(tmp, true, new CryptoPP::StreamTransformationFilter(dec, new CryptoPP::StringSink(result)));
        }
        catch(const CryptoPP::Exception& e)
        {
            std::cerr << "ERROR: \"libprge::cryptographyFunctions::streamCipher::rc6decrypt\":\n" << e.what() << '\n';
        }

        return result;
    }
#endif // LIBPRGE_USING_CRYPTOPP_CMAKE
} // namespace streamCipher

} // namespace cryptographyFunctions
} // namespace libprge
