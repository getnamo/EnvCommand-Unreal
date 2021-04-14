# env-command-unreal
Access environment variables from blueprint.

## API

Use one of the two BPLibrary functions.

![image](https://user-images.githubusercontent.com/542365/114750205-95980800-9d08-11eb-97a1-872dbe100735.png)

NB: ```SetEnvironmentVariable``` only sets it for the current process and is temporary. It won't live past current program run.
