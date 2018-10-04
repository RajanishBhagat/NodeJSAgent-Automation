1. Add following entry in .bashrc file 

export NDE_ATMN_WORK_DIR=${HOME}/workspac
WORKBENCH=${HOME}/workspace/
LOGS=${HOME}/workspace/logs
SMOKE=${WORKBENCH}/smoke
RESULTS=${HOME}/workspace/results
PERFORMANCE=${WORKBENCH}/performance

export LOGS                                                                                    
export RESULTS                                                                                 
export SMOKE                                                                                   
export WORKBENCH                                                                               
export PERFORMANCE                                                                             
#PATH=$PATH:$HOME/workspace/scripts
. /home/cavisson/bin/nsi_controller_selection_profile

cd ${WORKBENCH}


2. create a directory "workspace" inside home  and keep code here

/home/cavisson/workspace

Structure Example : 

root@netstorm-ProLiant-ML10-v2:/home/cavisson/workspace# ls -ltr
total 12
drwxrwxr-x 7 cavisson cavisson 4096 Oct  5 03:11 netjsagent
drwxrwxr-x 2 cavisson cavisson 4096 Oct  5 03:15 scripts
-rw-rw-r-- 1 cavisson cavisson  903 Oct  5 03:26 ReadMe.txt
root@netstorm-ProLiant-ML10-v2:/home/cavisson/workspace# 


