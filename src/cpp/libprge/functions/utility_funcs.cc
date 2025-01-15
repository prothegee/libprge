#include "utility_funcs.hh"

namespace libprge
{
namespace utilityFunctions
{

namespace find
{
    void andReplaceAll(std::string & source, const std::string & query, const std::string & replacement)
    {
        size_t position = 0;

        while ((position = source.find(query, position)) != std::string::npos)
        {
            source.replace(position, query.size(), replacement);
            position += replacement.size();
        }
    }
} // namespace find

namespace generate
{
    std::string uuid(const int &version)
    {
        std::string result;

        auto defaultResult = []()
        {
            // current time in milliseconds (for time-based portion)
            auto now = std::chrono::system_clock::now();
            auto duration = now.time_since_epoch();
            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

            // split the timestamp into parts (100ns intervals from 15 October 1582) offset from epoch
            uint64_t timestamp = milliseconds * 10000 + 0x01B21DD213814000;

            uint32_t timeLow = static_cast<uint32_t>(timestamp & 0xFFFFFFFF);
            uint16_t timeMid = static_cast<uint16_t>((timestamp >> 32) & 0xFFFF);
            uint16_t timeHiAndVersion = static_cast<uint16_t>((timestamp >> 48) & 0x0FFF);

            // set version number (UUIDv1 = 0x1)
            timeHiAndVersion |= (1 << 12);

            // generate a random 48-bit node (simulating MAC address or random node identifier)
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<uint64_t> dis(0, 0xFFFFFFFFFFFF);  // 48-bit random value
            uint64_t node = dis(gen);

            // UUID string representation
            std::ostringstream uuid;
            uuid << std::hex << std::setfill('0');
            
            uuid << std::setw(8) << timeLow << "-";
            uuid << std::setw(4) << timeMid << "-";
            uuid << std::setw(4) << timeHiAndVersion << "-";
            
            // generate random 16-bit clock sequence (a value related to time-based UUID uniqueness)
            uint16_t clockSeq = dis(gen) & 0x3FFF;  // 14 bits for clockSeq
            
            uuid << std::setw(4) << clockSeq << "-";
            uuid << std::setw(12) << (node & 0xFFFFFFFFFFFF);  // 48-bit node as last part

            return uuid.str();
        };

        switch (version)
        {
            case 1:
            {
                result = defaultResult();
            }
            break;

            case 4:
            {
                // random number generator and distribution
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dis(0, 15);  // random hex digit (0-F)

                // create a 16-byte array (128 bits)
                unsigned char uuid[16];

                // fill the first 15 bytes with random values
                for (int i = 0; i < 16; ++i) {
                    uuid[i] = static_cast<unsigned char>(dis(gen));  // random byte [0, 15]
                }

                // set the version (4) in the 7th byte (bits 6-7)
                uuid[6] &= 0x0f;  // clear the top 4 bits
                uuid[6] |= 0x40;   // set the version bits (0100 xxxx)

                // set the variant (RFC 4122) in the 9th byte (bits 4-5)
                uuid[8] &= 0x3f;  // clear the top 2 bits
                uuid[8] |= 0x80;   // set the variant bits (10xx xxxx)

                // format the UUID as a string
                std::ostringstream uuidStr;
                uuidStr << std::hex << std::setfill('0');
                uuidStr << std::setw(2) << static_cast<int>(uuid[0]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[1]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[2]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[3]);
                uuidStr << "-";
                uuidStr << std::setw(2) << static_cast<int>(uuid[4]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[5]);
                uuidStr << "-";
                uuidStr << std::setw(2) << static_cast<int>(uuid[6]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[7]);
                uuidStr << "-";
                uuidStr << std::setw(2) << static_cast<int>(uuid[8]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[9]);
                uuidStr << "-";
                uuidStr << std::setw(2) << static_cast<int>(uuid[10]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[11]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[12]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[13]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[14]);
                uuidStr << std::setw(2) << static_cast<int>(uuid[15]);

                result = uuidStr.str();
            }
            break;

            default:
            {
                result = defaultResult();
            }
            break;
        }

        return result;
    }
} // namespace generate

} // namespace utilityFunctions
} // namespace libprge
