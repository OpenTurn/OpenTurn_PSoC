# OpenTurn_PSoC


# notes to myself how to create subtrees
notes:
git clone <repo>
git branch <work_branch>
git push -u origin <work_branch>
git checkout work

git subtree split -P software/ModusToolbox/BSP/TARGET_OpenTurn -b BSP_1_0
rmdir software\ModusToolbox\BSP\TARGET_OpenTurn /s
git subtree split -P software/src/OpenTurn_project -b APP_OpenTurn_project_1_0
rmdir software\src\OpenTurn_project /s
git subtree split -P software/src/OpenTurn_selftest -b APP_OpenTurn_selftest_1_0
rmdir software\src\OpenTurn_selftest /s

git commit -am "created subtrees for ModusToolbox"
git push

git push -u origin BSP_1_0
git push -u origin APP_OpenTurn_project_1_0
git push -u origin APP_OpenTurn_selftest_1_0

git subtree add -P software/ModusToolbox/BSP/TARGET_OpenTurn https://github.com/OpenTurn/OpenTurn_PSoC.git BSP_1_0
git subtree add -P software/src/OpenTurn_project https://github.com/OpenTurn/OpenTurn_PSoC.git APP_OpenTurn_project_1_0
git subtree add -P software/src/OpenTurn_selftest https://github.com/OpenTurn/OpenTurn_PSoC.git APP_OpenTurn_selftest_1_0

git push