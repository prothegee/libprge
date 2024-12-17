#include "iscene_controller.hh"

namespace libprge
{

ISceneController::~ISceneController()
{
    memfree(pIScene);
    memfree(pIRootNode);
}

String ISceneController::SScene::getSceneAsFileName(const Node *pParentNode)
{
    String result = STRINGS_SCENES::SCENE_IS_UNDEFINED;

    if (pParentNode)
    {
        result = pParentNode->get_tree()->get_current_scene()->get_scene_file_path();
    }

    return result;
}

String ISceneController::SScene::getSceneAsFilePath(const Node *pParentNode)
{
    String result = STRINGS_SCENES::SCENE_IS_UNDEFINED;

    if (pParentNode)
    {
        result = pParentNode->get_tree()->get_current_scene()->get_scene_file_path();

        std::string tmpName = result.ascii().get_data();

        if (tmpName.find(".res") != std::string::npos)
        {
            utilityFunctions::find::andReplaceAll(tmpName, ".res", "");
        }

        if (tmpName.find(".scn") != std::string::npos)
        {
            utilityFunctions::find::andReplaceAll(tmpName, ".scn", "");
        }

        if (tmpName.find(".tscn") != std::string::npos)
        {
            utilityFunctions::find::andReplaceAll(tmpName, ".tscn", "");
        }

        result = tmpName.c_str();
    }

    return result;
}

void ISceneController::SScene::setActiveSceneTo(const Node *pParentNode, const String &sceneFilePath)
{
    try
    {
        pParentNode->get_tree()->call_deferred(CALL_DEFFERED::CHANGE_SCENE_TO_FILE, sceneFilePath);
    }
    catch(const std::exception& e)
    {
        logger::log::errorAlways(e.what());
    }
}

} // namespace libprge
