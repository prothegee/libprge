#ifndef LIBPRGE_IIN_GAME_CONTROLLER_HH
#define LIBPRGE_IIN_GAME_CONTROLLER_HH
#include <libprge/base/config.hh>

#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/node.hpp>

namespace libprge
{

/**
 * @brief "in-game" controller interface class
 */
class IInGameController
{
private:
    /* data */

public:
    virtual ~IInGameController();

    /**
     * @brief on _ready "in-game" 1unction runtime implementation
     * 
     * @note leave it empty body if not implemented
     */
    virtual void onReadyInGameRT() = 0;

    /**
     * @brief on _process "in-game" function runtime implementation
     * 
     * @note leave it empty body if not implemented
     */
    virtual void onProcessInGameRT() = 0;

    /**
     * @brief on _physics_process "in-game" function runtime implementation
     * 
     * @note leave it empty body if not implemented
     */
    virtual void onPhysicsProcessInGameRT() = 0;
};

} // namespace libprge

#endif // LIBPRGE_IIN_GAME_CONTROLLER_HH
