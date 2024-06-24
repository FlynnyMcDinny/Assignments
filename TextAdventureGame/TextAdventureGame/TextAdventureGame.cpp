#include "TextAdventureGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "BoxOfDonuts.h"
#include "Cat.h"
#include "Lamp.h"

void main()
{
    TextAdventureGame game;
    game.Game();
}

void TextAdventureGame::Game()
{   
    std::string input;
    std::cout << " TEXT BASED ADVENTURE GAME\n\n Welcome to this text based adventure game, you will be able to move inbetween rooms and interact with the objects in them.\n I hope you enjoy exploring the different rooms and interacting with them in different ways.\n\n Commands:\n 'north,east,south,west' These commands will move you in their respective directions.\n 'use' Lets you interact with the item in the room.\n 'inventory' Displays your inventory.\n 'shoot' If there are enemies in the room and you have a shotgun, they will be shot and die.\n" << std::endl;
    system("pause");
    std::cout << "\n";
    rooms[player.x][player.y].RoomGenerator();
    rooms[player.x][player.y].generated = true;
    rooms[player.x][player.y].Description();
    while (true)
    {
        std::cin >> input;
        if (input == "north")
        {
            if (player.x == 0)
            {
                std::cout << "|YOU CANT MOVE THAT WAY|" << std::endl;
            }
            else
            {           
                player.x -= 1;
                if (rooms[player.x][player.y].generated == false) 
                {
                    rooms[player.x][player.y].RoomGenerator();
                    rooms[player.x][player.y].generated = true;
                    rooms[player.x][player.y].Description();
                }    
                else 
                {
                    rooms[player.x][player.y].Description();
                }
            }
        }
        else if (input == "south")
        {
            if (player.x == 2)
            {
                std::cout << "|YOU CANT MOVE THAT WAY|" << std::endl;
            }
            else
            {
                player.x += 1;
                if (rooms[player.x][player.y].generated == false)
                {
                    rooms[player.x][player.y].RoomGenerator();
                    rooms[player.x][player.y].generated = true;
                    rooms[player.x][player.y].Description();
                }
                else
                {
                    rooms[player.x][player.y].Description();
                }
            }
        }
        else if (input == "east")
        {
            if (player.y == 2)
            {
                std::cout << "|YOU CANT MOVE THAT WAY|" << std::endl;
            }
            else
            {
                player.y += 1;
                if (rooms[player.x][player.y].generated == false)
                {
                    rooms[player.x][player.y].RoomGenerator();
                    rooms[player.x][player.y].generated = true;
                    rooms[player.x][player.y].Description();
                }
                else
                {
                    rooms[player.x][player.y].Description();
                }
            }
        }
        else if (input == "west")
        {
            if (player.y == 0)
            {
                std::cout << "|YOU CANT MOVE THAT WAY|" << std::endl;
            }
            else
            {
                player.y -= 1;
                if (rooms[player.x][player.y].generated == false)
                {
                    rooms[player.x][player.y].RoomGenerator();
                    rooms[player.x][player.y].generated = true;
                    rooms[player.x][player.y].Description();
                }
                else
                {
                    rooms[player.x][player.y].Description();
                }
            }
        }

        else if (input == "shoot")
        {
            if (room.shotgun.hasShotgun == false)
            {
                for (int i = 0; i < 5; i++)
                {
                    room.shotgun.ammo = std::to_string(room.shotgun.sAmmo);
                    if (player.inventory[i] == "Shotgun: \nAmmo: " + room.shotgun.ammo);
                    {
                        room.shotgun.hasShotgun = true;
                    }
                }
            }
            if (room.shotgun.sAmmo > 0 && rooms[player.x][player.y].itemnum == 5)
            {
                room.shotgun.sAmmo -= 1;
                room.shotgun.ammo = std::to_string(room.shotgun.sAmmo);
                std::cout << "You shot the creatures and killed them, you now have " + room.shotgun.ammo + " ammo." << std::endl;
                rooms[player.x][player.y].item = &rooms[player.x][player.y].empty;
            }

            else if (room.shotgun.hasShotgun == false)
            {
                std::cout << "|YOU DON'T HAVE A SHOTGUN|" << std::endl;
            }

            else if (room.shotgun.sAmmo <= 0)
            {
                std::cout << "|YOU ARE OUT OF AMMO|" << std::endl;
            }
        }

        else if (input == "use" && rooms[player.x][player.y].itemnum == 0)
        {
            rooms[player.x][player.y].boxofdonuts.Use();
        }
        else if (input == "use" && rooms[player.x][player.y].itemnum == 1)
        {
            rooms[player.x][player.y].cat.Use();
        }
        else if (input == "use" && rooms[player.x][player.y].itemnum == 2)
        {
            rooms[player.x][player.y].lamp.Use();
        }
        else if (input == "use" && rooms[player.x][player.y].itemnum == 3)
        {
            if (rooms[player.x][player.y].pickedUp == false)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (player.inventory[i] == "" && rooms[player.x][player.y].pickedUp == false)
                    {
                        if (rooms[player.x][player.y].itemnum == 3)
                        {
                            rooms[player.x][player.y].pickedUp = true;
                            rooms[player.x][player.y].item = &rooms[player.x][player.y].empty;
                            room.shotgun.hasShotgun = true;
                            room.shotgun.sAmmo += 5;
                            room.shotgun.ammo = std::to_string(room.shotgun.sAmmo);
                            player.inventory[i] = "Shotgun: \nAmmo: " + room.shotgun.ammo;
                            std::cout << "You picked up a Shotgun with " + room.shotgun.ammo + " ammo." << std::endl;
                        }
                    }
                }
            }
            else
            {
                std::cout << "|YOU HAVE NO MORE INVENTORY SPACE|" << std::endl;
            }
            }
        else if (input == "use" && rooms[player.x][player.y].itemnum == 4)
        {
            rooms[player.x][player.y].empty.Use();
        }
        else if (input == "use" && rooms[player.x][player.y].itemnum == 5)
        {
            rooms[player.x][player.y].enemy.Use();
        }

        else if (input == "inventory")
        {
            for (int i = 0; i < 5; i++)
            {
                if (player.inventory[i] != "")
                {
                    std::cout << player.inventory[i] << std::endl;
                }
            }
        }
        else if (rooms[player.x][player.y].pickedUp == true)
        {
            std::cout << "|YOU HAVE ALREADY PICKED THIS UP|" << std::endl;
        }
        else
        {
            std::cout << "|NOT A VALID INPUT|" << std::endl;
        }
    }
}
