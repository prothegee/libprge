#ifndef LIBPRGE_CRYPTOGRAPHY_FUNCS_HH
#define LIBPRGE_CRYPTOGRAPHY_FUNCS_HH
#include <libprge/base/config.hh>

#include <string>

#if LIBPRGE_USING_CRYPTOPP_CMAKE
#include <cryptopp/ec2n.h>
#include <cryptopp/hex.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/secblock.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/words.h>

#include <cryptopp/blake2.h>
#include <cryptopp/scrypt.h>
#include <cryptopp/sha.h>
#include <cryptopp/gcm.h>
#include <cryptopp/aes.h>
#include <cryptopp/chacha.h>
#include <cryptopp/rc6.h>
#endif // LIBPRGE_USING_CRYPTOPP_CMAKE

/**
 * @brief ENUM
 * 
 */
enum ECryptographyMode : i32
{
    CRYPTOGRAPHY_MODE_UNDEFINED,
    #if LIBPRGE_USING_CRYPTOPP_CMAKE
    CRYPTOGRAPHY_MODE_CRYPTOPP,
    #endif // LIBPRGE_USING_CRYPTOPP_CMAKE
};

namespace libprge
{
namespace cryptographyFunctions
{

namespace hash
{
    /**
     * @brief generate sha1 from input param
     * 
     * @note return length is 40
     * 
     * @param input 
     * @param mode 
     * @return std::string 
     */
    std::string sha1(const std::string &input, const ECryptographyMode &mode = CRYPTOGRAPHY_MODE_CRYPTOPP);

    /**
     * @brief generate sha224 from input param
     * 
     * @note return length is 56
     * 
     * @param input 
     * @param mode 
     * @return std::string 
     */
    std::string sha224(const std::string &input, const ECryptographyMode &mode = CRYPTOGRAPHY_MODE_CRYPTOPP);

    /**
     * @brief generate sha256 from input param
     * 
     * @note return length is 64
     * 
     * @param input 
     * @param mode 
     * @return std::string 
     */
    std::string sha256(const std::string &input, const ECryptographyMode &mode = CRYPTOGRAPHY_MODE_CRYPTOPP);

    /**
     * @brief generate sha384 from input param
     * 
     * @note return length is 96
     * 
     * @param input 
     * @param mode 
     * @return std::string 
     */
    std::string sha384(const std::string &input, const ECryptographyMode &mode = CRYPTOGRAPHY_MODE_CRYPTOPP);

    /**
     * @brief generate sha512 from input param
     * 
     * @note return length is 128
     * 
     * @param input 
     * @param mode 
     * @return std::string 
     */
    std::string sha512(const std::string &input, const ECryptographyMode &mode = CRYPTOGRAPHY_MODE_CRYPTOPP);

    #if LIBPRGE_USING_CRYPTOPP_CMAKE
    /**
     * @brief scrypt password hasher using cryptopp
     * 
     * @note you may adjust computationCost, blockSizeCost, threadsCost, & derivedLength as you need
     * 
     * @param input 
     * @param salt 
     * @param computationCost 
     * @param blockSizeCost 
     * @param threadsCost 
     * @param derivedLength 
     * @return std::string 
     */
    std::string scrypt(const std::string &input, const std::string &salt, const CryptoPP::word64 &computationCost = (2<<16), const CryptoPP::word64 &blockSizeCost = 8, const CryptoPP::word64 &threadsCost = 12, const uint32_t &derivedLength = 32);
    #endif // LIBPRGE_USING_CRYPTOPP_CMAKE
} // namespace hash

namespace streamCipher
{
    #if LIBPRGE_USING_CRYPTOPP_CMAKE
    /**
     * @brief encrypt input using CBC AES Rijndael stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16
     * @param ik ik recomendation length is 16 to 32
     * @return std::string 
     */
    std::string aesEncrypt(const std::string &input, const std::string &iv, const std::string &ik);
    /**
     * @brief decrypt input using CBC AES Rijndael stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16
     * @param ik ik recomendation length is 16 to 32
     * @return std::string 
     */
    std::string aesDecrypt(const std::string &input, const std::string &iv, const std::string &ik);

    /**
     * @brief encrypt input using XChaCha20 stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 24
     * @param ik ik recomendation length is 32
     * @return std::string 
     */
    std::string xChaCha20encrypt(const std::string &input, const std::string &iv, const std::string &ik);
    /**
     * @brief decrypt input using XChaCha20 stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 24
     * @param ik ik recomendation length is 32
     * @return std::string 
     */
    std::string xChaCha20decrypt(const std::string &input, const std::string &iv, const std::string &ik);

    /**
     * @brief encrypt input using CBC R6 stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16
     * @param ik ik recomendation length is 16 to 32
     * @return std::string 
     */
    std::string rc6encrypt(const std::string &input, const std::string &iv, const std::string &ik);
    /**
     * @brief encrypt input using CBC R6 stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16
     * @param ik ik recomendation length is 16 to 32
     * @return std::string 
     */
    std::string rc6decrypt(const std::string &input, const std::string &iv, const std::string &ik);
    #endif // LIBPRGE_USING_CRYPTOPP_CMAKE
} // namespace streamCipher

} // namespace cryptographyFunctions
} // namespace libprge

#endif // LIBPRGE_CRYPTOGRAPHY_FUNCS_HH
