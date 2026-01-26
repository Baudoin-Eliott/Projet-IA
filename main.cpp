#include <iostream>
#include <conio.h>
#include "Timer.h"
#include "Gun.h"
#include "IdleStateGun.h"
#include "ReloadStateGun.h"
#include "ShootStateGun.h"



int main() {
	Gun gun = Gun(10, 0.5f, 1.5);

    Timer timer = Timer();
    bool isRunning = true;
    float start = timer.Start();

    while (isRunning)
    {
      
        if (_kbhit() == 1) 
        {
            //input start
            if (gun.GetCurrentState() == State::Idle) {
          
                int key = _getch();
                switch (key) {
                case(114):
                    if (gun.GetStates()[(int)State::Reloading]->CanTransitionFrom(&gun, gun.GetCurrentState()))
                        if(gun.CanReload())
                            gun.SetState(State::Reloading);
                    break;
                case(115):
                    if (gun.GetStates()[(int)State::Shooting]->CanTransitionFrom(&gun, gun.GetCurrentState()))
						if (gun.CanShoot())
                            gun.SetState(State::Shooting);
                    break;
                case(113):
                    isRunning = false;
                    break;
                }
            }
            //input end
        }

        

        //deltaTime start
        float end = timer.End();
        float deltaTime = (end - start) / 1000.f;
        start = timer.Start();
        //deltaTime end



        gun.Update(deltaTime *1000);

    }
	return 0;
}