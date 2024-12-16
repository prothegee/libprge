#ifndef LIBPRGE_LIBPRGE_HH
#define LIBPRGE_LIBPRGE_HH
#include <libprge/base/config.hh>

#include <gdextension_interface.h>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/classes/engine.hpp>

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/ref_counted.hpp>

namespace libprge
{

using namespace godot;

static const char *CLibPrGe_CLASS = "CLibPrGe";
static const char *CLIBPRGE_BRIEF = R"(class CLibPrGe final
* @brief core libprge class
*
* @note meant to be use internal only
)";

/**
 * @brief core libprge class
 * 
 * @note meant to be use internal only
 */
class CLibPrGe final : public Object
{
    GDCLASS(CLibPrGe, Object);
private:
    inline static CLibPrGe *m_pThis;

protected:
    static void _bind_methods();

public:
    CLibPrGe(/* args */);
    ~CLibPrGe();

    static CLibPrGe *pGet() { return m_pThis; }
};

// libprge main class pointer
static CLibPrGe *pLibPrGe;

} // namespace libprge

/**
 * @brief initialize all pointers for libprge
 * 
 * @note mostly important ones
 * @note also all those pointer meant to be use internally
 */
inline static void libprge_initialize_pointers()
{
    if (!libprge::pLibPrGe) { libprge::pLibPrGe = libprge::CLibPrGe::pGet(); }
}

#endif // LIBPRGE_LIBPRGE_HH
