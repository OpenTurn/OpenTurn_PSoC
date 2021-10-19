# OpenTurn_PSoC


# notes to myself how to create subtrees
```
Create subtrees:
git clone https://github.com/OpenTurn/OpenTurn_PSoC.git
cd OpenTurn_PSoC
git branch v1.0.0
git push -u origin v1.0.0
git checkout v1.0.0

!!! copy code here !!!
!!! commit code here !!!
!!! push code here !!!

git subtree split -P hardware -b hardware
rmdir hardware /s /Q
git subtree split -P documentation -b documentation
rmdir documentation /s /Q

git subtree split -P software/ModusToolbox/BSP/TARGET_OpenTurn -b BSP_1_0
rmdir software\ModusToolbox\BSP\TARGET_OpenTurn /s /Q
git subtree split -P software/src/OpenTurn_project -b APP_OpenTurn_project_1_0
rmdir software\src\OpenTurn_project /s /Q
git subtree split -P software/src/OpenTurn_selftest -b APP_OpenTurn_selftest_1_0
rmdir software\src\OpenTurn_selftest /s /Q

git commit -am "created subtrees for ModusToolbox"
git push

git push -u origin hardware
git push -u origin documentation
git push -u origin BSP_1_0
git push -u origin APP_OpenTurn_project_1_0
git push -u origin APP_OpenTurn_selftest_1_0

git subtree add -P hardware https://github.com/OpenTurn/OpenTurn_PSoC.git hardware
git subtree add -P documentation https://github.com/OpenTurn/OpenTurn_PSoC.git documentation
git subtree add -P software/ModusToolbox/BSP/TARGET_OpenTurn https://github.com/OpenTurn/OpenTurn_PSoC.git BSP_1_0
git subtree add -P software/src/OpenTurn_project https://github.com/OpenTurn/OpenTurn_PSoC.git APP_OpenTurn_project_1_0
git subtree add -P software/src/OpenTurn_selftest https://github.com/OpenTurn/OpenTurn_PSoC.git APP_OpenTurn_selftest_1_0

git push

pull Subtree changes to master:
git checkout <subtree branch>
... do changes ...
git commit -m "<commit description>"
git push
git checkout v1.0.0
git subtree pull -P software/src/OpenTurn_project https://github.com/OpenTurn/OpenTurn_PSoC.git APP_OpenTurn_project_1_0



still testing...
Subtree push:
git checkout v1.0.0
... do changes ...
git commit -m "<commit description>"
git subtree push -P <subtree branch> https://github.com/OpenTurn/OpenTurn_PSoC.git <subtree branch>


```