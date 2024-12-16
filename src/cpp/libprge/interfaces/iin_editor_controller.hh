#ifndef LIBPRGE_IIN_EDITOR_CONTROLLER_HH
#define LIBPRGE_IIN_EDITOR_CONTROLLER_HH

namespace libprge
{

/**
 * @brief "in-editor" controller interface class
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
