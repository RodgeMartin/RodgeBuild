#include <Geode/Geode.hpp>  
#include <Geode/modify/EditorUI.hpp>  
  
using namespace geode::prelude;  
  
// v0.1 is deliberately a safe UI/load test. It does not edit level objects yet.  
class $modify(RodgeBuildEditorUI, EditorUI) {  
    bool init(LevelEditorLayer* editorLayer) {  
        if (!EditorUI::init(editorLayer)) {  
            return false;  
        }  
  
        auto label = CCLabelBMFont::create("RB", "bigFont.fnt");  
        if (!label) {  
            log::warn("RodgeBuild: could not create editor button label");  
            return true;  
        }  
  
        auto button = CCMenuItemLabel::create(  
            label,  
            this,  
            menu_selector(RodgeBuildEditorUI::onRodgeBuild)  
        );  
  
        if (!button) {  
            log::warn("RodgeBuild: could not create editor button");  
            return true;  
        }  
  
        button->setScale(0.55f);  
  
        auto menu = CCMenu::createWithItem(button);  
        if (!menu) {  
            log::warn("RodgeBuild: could not create editor menu");  
            return true;  
        }  
  
        auto winSize = CCDirector::sharedDirector()->getWinSize();  
        menu->setPosition({ winSize.width - 34.f, winSize.height * 0.58f });  
        menu->setID("rodgebuild-editor-menu"_spr);  
        button->setID("rodgebuild-open-button"_spr);  
  
        // Add as a high-z child so the prototype button stays visible.  
        this->addChild(menu, 999);  
  
        log::info("RodgeBuild v0.1 loaded into the level editor");  
        return true;  
    }  
  
    void onRodgeBuild(CCObject*) {  
        FLAlertLayer::create(  
            "RodgeBuild v0.1",  
            "<cy>NEON TEMPLATE PACK</c>\n\n"  
            "<cb>NEON BLUE</c> - cyan glow concept\n"  
            "<cp>NEON PURPLE</c> - purple/pink glow concept\n"  
            "<cg>NEON GREEN</c> - green digital glow concept\n\n"  
            "This is the first editor-load test. Template preview and object placement "  
            "are not implemented yet. No level objects have been changed.",  
            "Close"  
        )->show();  
    }  
};  
