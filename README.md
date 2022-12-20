# c-_gamedev


After SDL installation

Add this post build command for the Assets folder : rm -rf ${workspace_loc:/${ProjName}}/${ConfigName}/Assets;mkdir ${workspace_loc:/${ProjName}}/${ConfigName}/Assets;cp -rf ${workspace_loc:/${ProjName}}/src/Assets ${Workspace_loc:/${ProjName}}/${ConfigName}
