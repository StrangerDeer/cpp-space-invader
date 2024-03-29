<a name="readme-top"></a>
<br />
<div align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/4a7e2879-b5a6-47cc-b892-27a46f661ea0" alt="Logo" width="200" height="200">
  </a>
<h1 align="center">Stellar Storm</h1>
</div>


<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#running-the-game">Running The Game</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a>
      <ul>
        <li><a href="#finished-features">Finished Features</a></li>
      </ul>
      <ul>
        <li><a href="#planned-features">Planned Features</a></li>
      </ul>
    </li>
    <li><a href="#credits">Credits</a></li>
  </ol>
</details>



## About The Project

Inspired by the classic Space Invaders, Stellar Storm is an arcade-style game in which the player navigates their spaceship through a dangerous asteroid belt. The player has to catch falling stars to score points while avoiding the oncoming asteroids. To help in their journey, the player's spaceship is equipped with a gun with which they can shoot the asteroids they can't avoid. As they progress through the asteroid belt, the player will soon encounter hostile aliens with unpredictable movement and fire. Upon defeating an alien, it drops a health restoration bubble, which can aid greatly in the player's adventure through the belt.
<br>

For future features, see the <a href="#roadmap">roadmap</a>!

<p align="right">(<a href="#readme-top">back to top</a>)</p>


### Built With

* ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
* [SDL2](https://www.libsdl.org)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Getting Started
The project is still under development - once the first release is ready, an installer will be made available.

### Running The Game:
The project uses SDL2, SDL2 image, SDL2 ttf and SDL2 mixer.<br>
We use Visual Studio toolchain in CLion, and compiler is cl.

In Clion:

* Download vcpkg in Clion
* Download in vcpkg:
    * sdl2
    * sdl2 image
    * sdl2 ttf
    * sdl2 mixer and sdl2 mixer ext
* Settings -> CMake -> Cache variables
* You must add all variable's paths. You can find all paths .vcpkg-clion\vcpkg\installed\x64-windows\share. The base location, in windows, C:\Users\user.
* Build the project
* Copy every dll from the vcpkg directory to build directory. ( .vcpkg-clion\vcpkg\installed\x64-windows\bin , .vcpkg-clion\vcpkg\installed\x64-windows\debug )

After this, you will be ready to run the application!

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Usage

Controls:
* Arrow keys for the movement
* Space to shoot
<br>
<br>

![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/5b3b9cad-12c9-4a39-a054-675b96117459)

When starting the game, you will be met with the title screen. After pressing space, the game will begin, and you can control your spaceship ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/b1f7fc10-cc44-432b-ac6c-b581e3293d38).
<br>
Throughout the game, you have to catch falling stars ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/101d6603-5af6-4966-afa9-ed064d48026b) to score points (bottom right of the screen) and avoid asteroids ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/94c297bf-4ec2-4ffa-96a1-9d528a85d719) which deplete the spaceship's health upon impact (bottom left of the screen).

After a while, you will be meeting hostile aliens ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/b3eff62b-e956-4f28-a8d8-8cf0f13ce163) who will not hesitate to open fire at your spaceship. Their movement is pretty unpredictable, but they can be defeated. Once defeated, it will drop a healing bubble ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/e7175e9a-6d23-4390-92d8-d8f587710131) that you can pick up to restore some of your spaceship's health.

![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/ae859575-f5ff-4d0a-b832-70b6a6feab40)
![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/5494d712-ad30-494c-8210-e01d63fd3495)
<br>
<br>

Once your spaceship's health reaches zero, you will get a game over scene with your score displayed. You can press space to start again.

![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/eb9e2872-fa12-48e8-97e1-5ff802e3fdac)


<img src="https://github.com/rBabett/hyperbloom/assets/113454591/d0164a49-36f2-4c45-8ed7-ad62696df50d" width="120" height="120"/>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Roadmap

### Finished Features:

- [X] Spaceship movements
- [X] Falling stars
  - [X] Score points when caught
- [X] Falling asteroids
  - [X] Damage spaceship upon collision
- [X] Background music
- [X] Alien enemies
  - [X] Random movement
  - [X] Randomly firing
    - [X] Damage spaceship when shot
  - [X] Drop healing item
- [X] Ability to shoot
  - [X] Damage asteroids when shot
  - [X] Damage alien when shot
- [X] Healing item
  - [X] Restore HP when caught
- [X] Random background images
  - [X] Repeat background images
- [X] Sound effects
  - [X] Catching a star
  - [X] Colliding with asteroid
  - [X] Asteroid destroyed
  - [X] Shooting at the alien
  - [X] Catching healing item
- [X] Start scene
- [X] Game over scene
  - [X] Can restart

### Planned Features:
- [ ] Looping background music
- [ ] Installer
- [ ] Restrict spaceship movement so collision with an alien is no longer possible
- [ ] Speed boost items
- [ ] Increase game speed based on score
- [ ] Fix background images not appearing when restarting after a game over
- [ ] Fix music not playing when restarting after a game over

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Credits
* Music by Kevin MacLeod
* Sprites by [rBabett](https://github.com/rBabett)
* Developed by [StrangerDeer](https://github.com/StrangerDeer), [kri-nem](https://github.com/kri-nem) and [rBabett](https://github.com/rBabett)

<p align="right">(<a href="#readme-top">back to top</a>)</p>
