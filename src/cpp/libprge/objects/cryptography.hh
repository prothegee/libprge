#ifndef LIBPRGE_CRYPTOGRAPHY_HH
#define LIBPRGE_CRYPTOGRAPHY_HH
#include <libprge/libprge.hh>
#include <libprge/functions/cryptography_funcs.hh>

#include <godot_cpp/classes/object.hpp>

/**
 * @brief libprge cryptography object class
 */
class CCryptography : public Object
{
    GDCLASS(CCryptography, Object);
private:
    /* data */

protected:
    static void _bind_methods();

public:
    CCryptography(/* args */);
    ~CCryptography();

    //////////////////////////////////////////////////////

    /**
     * @brief generate sha1 from input param
     * 
     * @note return length is 40
     * 
     * @param input 
     * @return String 
     */
    String sha1(const String input);

    //////////////////////////////////////////////////////

    /**
     * @brief generate sha224 from input param
     * 
     * @note return length is 56
     * 
     * @param input 
     * @return String 
     */
    String sha224(const String input);

    //////////////////////////////////////////////////////

    /**
     * @brief generate sha256 from input param
     * 
     * @note return length is 64
     * 
     * @param input 
     * @return String 
     */
    String sha256(const String input);

    //////////////////////////////////////////////////////

    /**
     * @brief generate sha384 from input param
     * 
     * @note return length is 96
     * 
     * @param input 
     * @return String 
     */
    String sha384(const String input);

    //////////////////////////////////////////////////////

    /**
     * @brief generate sha512 from input param
     * 
     * @note return length is 128
     * 
     * @param input 
     * @return String 
     */
    String sha512(const String input);

    //////////////////////////////////////////////////////

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
     * @return String 
     */
    String scrypt(const String input, const String salt, const ui64 computationCost = (2<<16), const ui64 blockSizeCost = 8, const CryptoPP::word64 threadsCost = 12, const ui32 derivedLength = 32);

    //////////////////////////////////////////////////////

    /**
     * @brief encrypt input using CBC AES Rijndael stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16
     * @param ik ik recomendation length is 16 to 32
     * @return String 
     */
    String aesEncrypt(const String input, const String iv, const String ik);

    /**
     * @brief decrypt input using CBC AES Rijndael stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16
     * @param ik ik recomendation length is 16 to 32
     * @return String 
     */
    String aesDecrypt(const String input, const String iv, const String ik);

    //////////////////////////////////////////////////////

    /**
     * @brief encrypt input using XChaCha20 stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16 to 24
     * @param ik ik recomendation length is 32
     * @return String 
     */
    String xChaCha20encrypt(const String input, const String iv, const String ik);

    /**
     * @brief decrypt input using XChaCha20 stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16 to 24
     * @param ik ik recomendation length is 32
     * @return String 
     */
    String xChaCha20decrypt(const String input, const String iv, const String ik);

    //////////////////////////////////////////////////////

    /**
     * @brief encrypt input using CBC R6 stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16
     * @param ik ik recomendation length is 16 to 32
     * @return String 
     */
    String rc6encrypt(const String input, const String iv, const String ik);

    /**
     * @brief decrypt input using CBC R6 stream cipher
     * 
     * @param input 
     * @param iv iv recomendation length is 16
     * @param ik ik recomendation length is 16 to 32
     * @return String 
     */
    String rc6decrypt(const String input, const String iv, const String ik);
};

// default class name for CCryptography
inline static cchar *CCryptography_CLASS = "CCryptography";

// global cryptography pointer
static CCryptography *pCryptography;

#endif // LIBPRGE_CRYPTOGRAPHY_HH
