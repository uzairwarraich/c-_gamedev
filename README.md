'''# c-_gamedev


## After SDL installation

Add this post build command for the Assets folder : 


 rm -rf ${workspace_loc:/${ProjName}}/${ConfigName}/Assets;mkdir ${workspace_loc:/${ProjName}}/${ConfigName}/Assets;cp -rf ${workspace_loc:/${ProjName}}/src/Assets ${Workspace_loc:/${ProjName}}/${ConfigName} 



'''

For error "undefined reference to sdl_init' ubuntu"


or Eclipse IDE:.

Select project
Project>Properties
C/C++ Build>Settings - Tool Settings>GCC C Compiler - Include paths (-l)>"/usr/include/SDL"
C/C++ Build>Settings - Tool Settings>GCC C Linker - Libraries (-l)>"SDL2"
Apply
...then build project and run...
