#ifndef LIBPRGE_IIN_EDITOR_CONTROLLER_HH
#define LIBPRGE_IIN_EDITOR_CONTROLLER_HH
#include <libprge/base/config.hh>

#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/node.hpp>

namespace libprge
{

/**
 * @brief "in-editor" controller interface class
 * 
 * @note there are two node from index of /root when editor:
 * @note 1. @EditorNode@nnnnn of "EditorNode"
 * @note 1. @ProgressDialog@nnnnn of "ProgressDialog"
 */
class IInEditorController
{
private:
    /* data */

public:
    virtual ~IInEditorController();

    /**
     * @brief on _ready "in-editor" 1unction runtime implementation
     * 
     * @note leave it empty body if not implemented
     */
    virtual void onReadyInEditorRT() = 0;

    /**
     * @brief on _process "in-editor" function runtime implementation
     * 
     * @note leave it empty body if not implemented
     */
    virtual void onProcessInEditorRT() = 0;

    /**
     * @brief on _physics_process "in-editor" function runtime implementation
     * 
     * @note leave it empty body if not implemented
     */
    virtual void onPhysicsProcessInEditorRT() = 0;
};

} // namespace libprge

#endif // LIBPRGE_IIN_EDITOR_CONTROLLER_HH
