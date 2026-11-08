# RodgeBuild v0.1 — source prototype

This is the first source milestone for the independent RodgeBuild Geode mod.

## Target
- Geometry Dash Android 2.208
- Geode 5.0.0-alpha.2
- Android ARM64 (`android64`) is the intended build target, pending confirmation of the app ABI.

## What this prototype does
- Hooks `EditorUI::init(LevelEditorLayer*)`.
- Adds a small `RB` button to the level editor.
- Opens a Geode/Geometry Dash alert listing the three planned neon themes.

## What it does NOT do yet
- It does not generate or place decoration objects.
- It does not recognize Smart Blocks or match structures.
- It does not contain actual reusable decoration templates.
- The alert is a temporary UI/load test, not the final custom popup.

## Build requirements
You need the Geode SDK/CLI and Android NDK configured for the exact Geode version. The official Geode Android build instructions use:

```sh
geode sdk install-binaries -p android64
geode build -p android64
```

The resulting `.geode` package is normally in the `build-android64` directory. Do not install a build compiled against a different Geode/game version.

## Install location
The Geode Android mods folder is commonly:

```text
Android/media/com.geode.launcher/game/geode/mods/
```

Copy the compiled `rodgemartin.rodgebuild.geode` file there and restart Geometry Dash.

## Important compatibility note
This is an initial source scaffold, not a compiled or tested `.geode` binary. The `EditorUI` hook and button position must be verified against the exact Android Geode 5.0.0-alpha.2 SDK/game bindings before treating it as a working release. If it fails to compile or the button is misplaced, use the Geode log and revise the hook/layout rather than forcing installation.
