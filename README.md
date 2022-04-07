# EnvCommand-Unreal
Access environment variables from blueprint.

## Install & Setup

1. Download [Latest Release](https://github.com/getnamo/EnvCommand-Unreal/releases)
2. Create new or choose project.
3. Browse to your project folder (typically found at ```Documents/Unreal Project/{Your Project Root}```)
4. Copy ```Plugins``` folder into your Project root.
5. If disabled by default, enable the plugin in your plugins window and restart the Editor to open your project again.
6. Plugin is now ready to use.

## API

Use one of the two BPLibrary functions.

![image](https://user-images.githubusercontent.com/542365/114750205-95980800-9d08-11eb-97a1-872dbe100735.png)

NB: ```SetEnvironmentVariable``` only sets it for the current process and is temporary. It won't live past current program run.
