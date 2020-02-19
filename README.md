# creator_steamsdk
creator 接入 steamsdk
主要是 creator 中 js与c++ 的沟通 官方文档写的太隐晦了。 研究了半天才明白

首先 构建项目,然后编译 一次，然后将以上文件 复制到 
build\jsb-default\frameworks\runtime-src\Classes  文件佳中  
将 steam_dll 中 的文件 复制到   
build\jsb-default\frameworks\runtime-src\proj.win32\Debug.win32    或
build\jsb-default\frameworks\runtime-src\proj.win32\Release.win32  文件夹中

使用 vs 打开 
build\jsb-default\frameworks\runtime-src\proj.win32\NewProject.vcxproj


在 其中 AppDelegate.cpp  文件中 增加

#include "steam_use.h"

在 bool AppDelegate::applicationDidFinishLaunching() 方法中
的   
se->start();
之后   
jsb_run_script("jsb-adapter/jsb-builtin.js");
jsb_run_script("main.js");
之前
增加

	steam_use mysteam_use;
	mysteam_use.init_steam();
	se::Object* globalObj = se::ScriptEngine::getInstance()->getGlobalObject(); 
  globalObj->setProperty("foo", se::Value(mysteam_use.steamsta));
	globalObj->setProperty("steamid", se::Value(mysteam_use.steamid));
	globalObj->setProperty("language", se::Value(mysteam_use.language));
 
 
 
 
 然后在  vs中调试 就可在 creator 中的 js 中 访问到 foo、steamid、language 的值了
