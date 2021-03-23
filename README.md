This ping example is an minimum example for an running isaac application written in C++!
interessting links about ping:
https://docs.nvidia.com/isaac/isaac/doc/tutorials/ping.html#cplusplus-ping
https://www.programmersought.com/article/91352791103/

additional info about codelets, mainly explained by the ping example:
https://docs.nvidia.com/isaac/isaac/doc/engine/alice.html

interesting links about bazel:
https://docs.bazel.build/versions/4.0.0/build-ref.html#workspaces

-----------------------------------------------------------------------------------------------------------------------------------
FILE: WORKSPACE
Every package needs one WORKSPACE-File. There are some lines, which need to be edited.
I) Line 29: edit the name of the package
II) Line 34 & 38: Path to isaac engine & sdk
III) Line 88: name of workspace
IV) Line 90: workspace param
-----------------------------------------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------------------------------------
FILE: BUILD
These files are necessary do mark a directory as workspace. It's possible to have them also in subdirectories. In the first directory it's necessary.
It seems also to be necessary in the directory with the source files.
For this application it's necessary to define the "isaac_app" and "isaac_cc_module". The defined object has to be set in the first line with "load"!
"@com_nvidia_isaac_sdk" is the path to the isaac sdk environment. Probably defined by the WORKSPACE file -> /opt/nvidia/isaac/sdk
In the example of Nvidia, they defined it in one file -> all files have to be in one directory
In this example it's diefined in two files (I found no other solution, but I think there are other solutions)

BUILD-file in "ping"-directory:
Defines the isaac_app:
I) name of application
II) directory to components (I think source files, with this syntax they expect "./packages/ping")

BUILD-file in "ping/packages/ping"-directory:
Defines the components for the application:
I) name of components
II) source files
III) header files
-----------------------------------------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------------------------------------
FILE: repositories.bzl
Is necessary in dedicated workspaces. Edit follwoing:
I) Line 34: workspace param (like in WORKSPACE-file Line 90)
-----------------------------------------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------------------------------------
FILE: .bazelrc
imports the bazelrc file from sdk! If there's a failure, check if this file is available in /opt/nvidia/isaac/.bazelrc
Be carefully copying this file. It's a hidden file, so "cp *" doesn't copy it.
Edit single line:
I) Line 1: import <global path of .bazelrc of isaac>
-----------------------------------------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------------------------------------
FILE: ping.app.json
I) application name and modules
II) graph and edges (edges is empty, because there are no nodes to communicate)
III) configuration with following definitions: node name, component name, parameter name with value
It's possible to write the value in seconds like 1.0s or as frequency like 1Hz
-----------------------------------------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------------------------------------
RUND AND BUILD
Build the application:
cd into ping-directory (cd ~/workspace/bazel_ws/ping)
bazel build application-name (bazel build ping)


Run and build if necessary
bazel run application-name (bazel run ping)
-----------------------------------------------------------------------------------------------------------------------------------
