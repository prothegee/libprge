#ifndef LIBPRGE_ISCENE_CONTROLLER_HH
#define LIBPRGE_ISCENE_CONTROLLER_HH
#include <libprge/base/config.hh>
#include <libprge/constants/string_const.hh>
#include <libprge/constants/call_const.hh>
#include <libprge/enums/result_enums.hh>

#include <libprge/functions/utility_funcs.hh>
#include <libprge/functions/logger_funcs.hh>

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/tree.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/window.hpp>

namespace libprge
{

using namespace godot;

/**
 * @brief scene controller interface class
 */
class ISceneController
{
private:
    /* data */

public:
    virtual ~ISceneController();

    /**
     * @brief scene structure
     */
    struct SScene
    {
        /**
         * @brief get scene as file name
         * 
         * @param pParentNode 
         * @return String 
         */
        String getSceneAsFileName(const Node *pParentNode);

        /**
         * @brief get scene as file path
         * 
         * @param pParentNode 
         * @return String 
         */
        String getSceneAsFilePath(const Node *pParentNode);

        /**
         * @brief set active scene to
         * 
         * @param pParentNode 
         * @param sceneFilePath 
         */
        void setActiveSceneTo(const Node *pParentNode, const String &sceneFilePath);

        /**
         * @brief add child from "/root" node
         * 
         * @note the <T> of pWhatNode node will be add under "/root" node
         * 
         * @tparam T 
         * @param pParentNode 
         * @param pWhatNode 
         * @return EResult::ENUM 
         */
        template <class T>
        EResult::ENUM addChild(Node *pParentNode, T *pWhatNode)
        {
            EResult::ENUM result = EResult::ENUM::RESULT_UNDEFINED;

            try
            {
                if (pParentNode)
                {
                    pRoot->call_deferred(CALL_DEFFERED::ADD_CHILD, pWhatNode);

                    result = EResult::ENUM::RESULT_OK;
                }
            }
            catch(const std::exception& e)
            {
                result = EResult::ENUM::RESULT_ERROR;

                logger::log::errorAlways(e.what());
            }

            return result;
        }
    };
    // pointer scene interface access
    SScene *pIScene = memnew(SScene);

    struct SRootNode
    {
        /**
         * @brief add child from "/root" node
         * 
         * @note the <T> of pWhatNode node will be add under "/root" node
         * 
         * @tparam T 
         * @param pParentNode 
         * @param pWhatNode 
         * @return EResult::ENUM 
         */
        template <class T>
        EResult::ENUM addChild(Node *pParentNode, T *pWhatNode)
        {
            EResult::ENUM result = EResult::ENUM::RESULT_UNDEFINED;

            try
            {
                bool found = false;
                auto pRoot = pParentNode->get_node<Node>("/root");

                result = EResult::ENUM::RESULT_FOUND;

                for (int i = 0; i < pParentNode->get_child_count(); i++)
                {
                    if (pRoot->get_child(i)->get_class() == pRoot->get_class()) { found = true; }
                }

                if (found)
                {
                    logger::log::warningAlways("core node of \"", pRoot->get_class(), "\" already exists with \"", pRoot->get_name(), "\" name, skipping");
                }

                if (!pRoot->get_node_or_null((NodePath)pWhatNode->get_name()) && !found)
                {
                    pRoot->call_deferred(CALL_DEFFERED::ADD_CHILD, pWhatNode);

                    result = EResult::ENUM::RESULT_OK;
                }
            }
            catch(const std::exception& e)
            {
                result = EResult::ENUM::RESULT_ERROR;

                logger::log::errorAlways(e.what());
            }

            return result;
        }

        /**
         * @brief get node relative <T> "/root" node
         * 
         * @tparam T 
         * @param pParentNode 
         * @param nodePath 
         * @return T* 
         */
        template <typename T>
        T *getNode(Node *pParentNode, const NodePath &nodePath)
        {
            T *result = nullptr;

            try
            {
                auto pRoot = pParentNode->get_node<Node>("/root");

                result = pRoot->get_node_or_null<T>(nodePath);
            }
            catch(const std::exception& e)
            {
                logger::log::errorAlways(e.what());
            }

            return result;
        }
    };
    // pointer root node interface access
    SRootNode *pIRootNode = memnew(SRootNode);

    /**
     * @brief get root node pointer
     * 
     * @param pParentNode mostly 'this'
     * @return Node* 
     */
    Node *pGetRootNode(Node *pParentNode) { return pParentNode->get_node<Node>("/root"); };

    /**
     * @brief get root window pointer
     * 
     * @param pParentNode mostly 'this'
     * @return Window* 
     */
    Window *pGetRootWindow(Node *pParentNode) { return pParentNode->get_node<Window>("/root"); };
};

} // namespace libprge

#endif // LIBPRGE_ISCENE_CONTROLLER_HH
