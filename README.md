Description
============
Robo Wars is a AI driven robot combat game. Each player is in charge of writing his robot's AI code. The player would then send his robot to complete against other players robot's.

There will be different upgrades for robots that players can buy in the shop. More on this will be explained below in "Current Vision"

For more detailed information on what has been discussed so far head on over to http://www.cplusplus.com/forum/lounge/119486/ . The wiki and more detailed information about this project should be availible soon.

Current Vision
===============

Robots get a certain amount of "money" to buy their parts. Better parts cost more money. But in the end, all robots cannot spend more than the amount (so if you want to invest in better weaponry, you'll suffer in other areas. It's a tradeoff).

Some ideas for parts would be:
- Wheels/Motor. Better parts would let you move/brake faster
- Cameras. Better parts would let you see further and/or wider angle.
- Guns. Better parts shoot faster bullets
- Alternative weaponry (lasers? mines?)
- Armor
- Chaff/Fog - something to hide you from other robot's cameras. (would have to be limited use)


Anything that is directional (cameras/weapons) would be turret based, so you'd have to orient it with the robot. Rotating/orientating would take time (doesn't move instantaneously) so maybe higher quality parts could rotate faster?

You could also have multiple guns/cameras that rotate independently.

=========================

The robots themselves would be "plugins". In the beginning of the progects lifetime this will most likely be accomplish by having each player submit his AI code to be compiled into the source of the game client. But if this project picks up speed another method might be devised which would allow for much easier submissions.

The interface would be a small set of functions:

- 1 to do the "shopping" for the robot. It would call back public functions to "purchase" items (obtaining a pointer to a Camera object, or the like)

- 1 called every "tick" in the battle to do a step of AI logic.


That'd be it. Most of the work would be done through the items the robots purchased. So if the logic wanted to rotate the gun to a certain angle, then fire a bullet, it could do something like this in its logic:

```cpp
maingun->rotateToAngle(desiredAngle);
if(maingun->getAngle() == desiredAngle)
    maingun->fire();
```


Where 'maingun' was the object obtained during the shopping step. As this illustrates, rotation is not immediate, and the robot has to poll the current angle of the gun to know if it's pointing where it wants it to point or not.


===================================

This makes it impossible to have "illegal moves" like you'd have in a chess or something game, because the only thing the AI here has control over is the parts its using. And if you try to do something illegal with the parts (like fire 2 bullets in the same logic update), the part can simply ignore it and/or return some kind of error.


To prevent robots from "deadlocking", we could run the logic in a separate thread and have it 'timeout' after a certain length of time. If the robot times out, the driving code could just kill the thread and then that robot would just be dead.


The modularity would allow anyone to submit robots by sending a dll (though that would be a security risk, so maybe we don't want to do that?). And in the main program we could match up whatever robots we wanted and pit them in battle! mwahahaha.

If we want to get really fancy we can add obstacles and stuff. or maybe have different "classes" of robots. So high class robots can spend more money, but get matched up against other higher class robots.
