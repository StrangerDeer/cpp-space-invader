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

Inspired by the classic Space Invaders, Stellar Storm is an arcade-style game in which the player navigates their spaceship through a dangerous asteroid belt. The player has to catch falling stars to score points while avoiding the oncoming asteroids. To help in their journey, the player's spaceship is equipped with a gun with which they can shoot the asteroids they can't avoid. As they progress through the asteroid belt, the player will soon encounter hostile aliens with unpredictable movement and fire. Defeating these aliens and catching their loot is essential to upgrade the ship and survive. Extra loot can be found in special asteroids containing rare crystals.
<br>

For future features, see the <a href="#roadmap">roadmap</a>!

<p align="right">(<a href="#readme-top">back to top</a>)</p>


### Built With

* ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
* [SDL2](https://www.libsdl.org)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Getting Started
The project is still under development - once the first release is ready, an installer will be made available.

You will need:
* Install CMake, Ninja and vcpkg
* env variable set for VCPKG_ROOT (`C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg`)
* add ninja to Path env variable

For Windows:
* build with build.ps1

For Linux:
* build with build.sh

### Running The Game:
Run cpp_space_invader.exe in build-cmake folder

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Usage

Controls:
* Arrow keys or WASD for the movement
* Space to shoot
<br>
<br>

![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/56e15a26-0663-428f-9301-9a9cdeeaf0f1)

When starting the game, you will be met with the title screen. You can press the buttons 1, 2 and 3 to toggle between spaceship sprites ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/b1f7fc10-cc44-432b-ac6c-b581e3293d38), ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/4662e807-044d-4d22-b014-e139f8ec2ee8), ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/c7ba3af9-1efb-4ade-8560-707f07586feb).
After pressing space, the game will begin, and you can control your spaceship.
<br>

Throughout the game, you have to catch falling stars ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/101d6603-5af6-4966-afa9-ed064d48026b) to score points (top right of the screen) - the harder it is to catch a certain star, the more points it provides. You must also avoid asteroids ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/94c297bf-4ec2-4ffa-96a1-9d528a85d719) which deplete the spaceship's health upon impact (bottom left of the screen).

After a while, you will be meeting hostile aliens ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/b3eff62b-e956-4f28-a8d8-8cf0f13ce163) who will not hesitate to open fire at your spaceship. Their movement is pretty unpredictable, but they can be defeated. Once defeated, the alien will drop one of the following items:
- a shield bubble ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/ed1371fc-64eb-4c0d-8db4-373dded48a7b) which negates your ship from taking any damage, but it doesn't last forever
- a gun booster bubble ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/6c61fdc9-fa82-430b-9d6f-ee71ad5d402a) which will level up your spaceship's gun (bottom left), increasing its fire rate
- a gun expansion bubble ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/1c2fafdb-5e72-4dc0-8fcd-0662702b0f0f) which adds more lines of fire to the spaceship's gun

Throughout your journey across the asteroid belt, you will find special asteroids containing rare crystals ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/a3e88eb3-8d2b-4619-bd03-209b69c24c5e). These precious crystals can give you the following:
- a healing bubble ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/e7175e9a-6d23-4390-92d8-d8f587710131) which restores some of your spaceship's health
- a time bubble ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/a38e4c3d-a28f-4f65-a9d6-25ab9c9fbb88) which warps time around the spaceship, making things slower
- a star bubble ![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/9e295f15-d96d-42d9-9b1d-ef7935be6e6e) which gives your ship extra points

The more stars you catch, the spaceship's travelling speed increases (bottom right), and aliens and asteroids will become harder to defeat.

![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/6107fdc2-2c63-4cd2-8531-b7c20bf481b4)
![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/dfd45d64-5067-48ed-bc50-aceb5d58c16c)

<br>
<br>

Once your spaceship's health reaches zero, you will get a game over scene with your score displayed. You can press space to start again.

![image](https://github.com/StrangerDeer/cpp-space-invader/assets/113454591/480ae7f6-f9ec-4908-a4b9-880515736d40)


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
  - [X] Drop items
    - [X] Healing item
    - [X] Gun booster
    - [X] Randomize drops
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
- [X] Gun booster
  - [X] Increase bullet speed
  - [X] Increase fire rate
  - [X] Picking up increases alien and asteroids' HP
- [X] Increase game speed based on score
- [X] Increase alien HP based on score
- [X] Text for current game difficulty (speed)
- [X] Gun pickup that adds more lines of fire
  - [X] Picking up increases alien and asteroids' HP
- [X] Add WASD to controls
- [X] Crystal asteroids that drop loot
- [X] Extra points (star) pickup
- [X] New sprites for asteroids, crystal asteroids, aliens and the spaceship taking damage
- [X] Fixed: music now restarts when restarting after game over
- [X] Fixed: Background music now loops
- [X] The game can be paused by pressing 'T'
- [X] Fixed: Background images now appear when restarting after game over
- [X] New spaceship sprites
  - [X] Enable choosing between spaceships before beginning the game
- [X] Shield pickup that protects the spaceship when taking damage
  - [X] Place shield sprite over spaceship's when active
- [X] Restrict spaceship movement so collision with an alien is no longer possible
- [X] Time slowing pickup that slows objects down around the spaceship
- [X] New sprites for asteroids, crystal asteroids and aliens getting destroyed
- [X] Time counter stops when game is paused
- [X] Make the game platform and OS independent

### Planned Features:
- [ ] Installer
- [ ] Difficulties: Easy, Medium, Hard
- [ ] Option to add name with a button to send the player's high score to the webpage

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Credits
* Music by Kevin MacLeod
* Sprites by [rBabett](https://github.com/rBabett)
* Developed by [StrangerDeer](https://github.com/StrangerDeer), [kri-nem](https://github.com/kri-nem) and [rBabett](https://github.com/rBabett)

<p align="right">(<a href="#readme-top">back to top</a>)</p>
