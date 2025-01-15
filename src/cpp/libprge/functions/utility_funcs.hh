#ifndef LIBPRGE_UTILITY_FUNCS_HH
#define LIBPRGE_UTILITY_FUNCS_HH
#include <libprge/base/config.hh>

#include <string>
#include <vector>
#include <random>
#include <array>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <ostream>
#include <iostream>

namespace libprge
{
namespace utilityFunctions
{

namespace find
{
    /**
     * @brief format string source, find match query and replace it
     * 
     * @param source 
     * @param query 
     * @param replacement 
     */
    void andReplaceAll(std::string &source, const std::string &query, const std::string &replacement);
} // namespace find

namespace generate
{
    /**
     * @brief generate uuid
     * 
     * @note only support v1 & v4
     * @note if version not v1/v4 return v1 instead
     * 
     * @param version 1 or 4
     * @return std::string 
     */
    std::string uuid(const int &version = 1);
} // namespace generate

} // namespace utilityFunctions
} // namespace libprge

#endif // LIBPRGE_UTILITY_FUNCS_HH
