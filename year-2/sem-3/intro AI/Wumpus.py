print("This is Karan Taneja's code. SAP - 500084399")


def learnagent(world, i, j):
    if (world[i][j] == 9):
        agi, agj = i, j
        print("\nNow the agent is at "+str(agi)+","+str(agj))
        print("You came across a stench")
        return agi, agj
    elif (world[i][j] == 8):
        agi, agj = i, j
        print("\nNow the agent is at "+str(agi)+","+str(agj))
        print("You came across a glitter")
        return agi, agj
    elif (world[i][j] == 7):
        agi, agj = i, j
        print("\nNow the agent is at "+str(agi)+","+str(agj))
        print("You came across a pit")
        return -5, -5
    elif (world[i][j] == 6):
        agi, agj = i, j
        print("\nNow the agent is at "+str(agi)+","+str(agj))
        print("You found gold")
        return -4, -4
    elif (world[i][j] == 5):
        agi, agj = i, j
        print("\nNow the agent is at "+str(agi)+","+str(agj))
        print("You feel breeze")
        return agi, agj
    elif (world[i][j] == -1):
        agi, agj = i, j
        print("\nNow the agent is at "+str(agi)+","+str(agj))
        print("You met wumpus")
        return -5, -5
    else:  # if world environment was empty
        agi, agj = i, j
        print("\nNow the agent is at "+str(agi)+","+str(agj))
        return agi, agj


def checkinp(agi, agj):
    if(agi == 0 and agj == 0):
        print("\nyou can go at 	"+str(agi+1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj+1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi+1 and agvj == agj or agvi == agi and agvj == agj+1):
            return agvi, agvj
        else:
            return -5
    elif(agi == 3 and agj == 0):
        print("\nyou can go at 	"+str(agi-1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj+1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi-1 and agvj == agj or agvi == agi and agvj == agj+1):
            return agvi, agvj
        else:
            return -5
    elif(agi == 3 and agj == 3):
        print("\nyou can go at 	"+str(agi-1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi-1 and agvj == agj or agvi == agi and agvj == agj-1):
            return agvi, agvj
        else:
            return -5
    elif(agi == 0 and agj == 3):
        print("\nyou can go at 	"+str(agi+1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi+1 and agvj == agj or agvi == agi and agvj == agj-1):
            return agvi, agvj
        else:
            return -5, -5
    elif(agi == 1 and agj == 0 or agi == 2 and agj == 0 or agi == 3 and agj == 0):
        print("\nyou can go at 	"+str(agi+1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj+1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi+1 and agvj == agj or agvi == agi and agvj == agj+1):
            return agvi, agvj
        else:
            return -5, -5
    elif(agi == 0 and agj == 3 or agi == 1 and agj == 3 or agi == 2 and agj == 3 or agi == 3 and agj == 3):
        print("you can go at 	"+str(agi+1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        agvi = int(input("Enter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi+1 and agvj == agj or agvi == agi and agvj == agj-1):
            return agvi, agvj
        else:
            return -5, -5
    elif(agi == 3 and agj == 1 or agi == 3 and agj == 2 or agi == 3 and agj == 3):
        print("\nyou can go at 	"+str(agi)+"	"+str(agj+1))
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        print("you can go at 	"+str(agi-1)+"	"+str(agj))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi and agvj == agj+1 or agvi == agi and agvj == agj-1 or agvi == agi-1 and agvj == agj):
            return agvi, agvj
        else:
            return -5, -5
    else:
        print("\nyou can go at 	"+str(agi)+"	"+str(agj+1))
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        print("you can go at 	"+str(agi+1)+"	"+str(agj))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi and agvj == agj+1 or agvi == agi and agvj == agj-1 or agvi == agi+1 and agvj == agj):
            return agvi, agvj
        else:
            return -5, -5


def checkinpreverse(agi, agj):
    if(agi == 0 and agj == 3):
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi and agvj == agj-1):
            return agvi, agvj
        else:
            return -5, -5
    elif(agi == 0 and agj == 2 or agi == 0 and agj == 1):
        print("you can go at 	"+str(agi)+"	"+str(agj+1))
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi and agvj == agj-1 or agvi == agi and agvj == agj+1):
            return agvi, agvj
        else:
            return -5, -5
    elif(agi == 1 and agj == 0 or agi == 2 and agj == 0):
        print("\nyou can go at 	"+str(agi-1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj+1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi-1 and agvj == agj or agvi == agi and agvj == agj+1):
            return agvi, agvj
        else:
            return -5, -5
    elif(agi == 1 and agj == 3 or agi == 2 and agj == 3):
        print("you can go at 	"+str(agi-1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        agvi = int(input("Enter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi-1 and agvj == agj or agvi == agi and agvj == agj-1):
            return agvi, agvj
        else:
            return -5, -5
    else:
        print("\nyou can go at 	"+str(agi-1)+"	"+str(agj))
        print("you can go at 	"+str(agi)+"	"+str(agj-1))
        print("you can go at 	"+str(agi)+"	"+str(agj+1))
        agvi = int(input("\nEnter input for row => "))
        agvj = int(input("Enter input for column => "))
        if(agvi == agi-1 and agvj == agj or agvi == agi and agvj == agj-1 or agvi == agi and agvj == agj+1):
            return agvi, agvj
        else:
            return -5, -5


world = [[0, 5, 7, 5],
         [9, 0, 8, 0],
         [-1, 6, 7, 8],
         [9, 0, 8, 7]	]  # declaration of the world

agi, agj = 0, 0  # initial agent position
print("\n\n\ninitially agent is at "+str(agi)+","+str(agj))
print("\nyou can go at 	"+str(agi+1)+"	"+str(agj))
print("you can go at 	"+str(agi)+"	"+str(agj+1))

agvi = int(input("Enter input for row => "))
agvj = int(input("Enter input for column => "))  # taking row and column values
if(agvi == 1 and agvj == 0 or agvi == 0 and agvj == 1):
    agi, agj = learnagent(world, agvi, agvj)
else:
    print("Not valid")

while(agi >= 0):
    agvi, agvj = checkinp(agi, agj)
    if(agvi != -5 and agvj != -5):
        agi, agj = learnagent(world, agvi, agvj)
    else:
        print("\nNot valid")

if(agi == -5):
    print("\nGame over Sorry try next time!!!")
else:
    print("\nYou have unlocked the next level. Move back to your initial position")

    agi, agj = 2, 1

    while(agi >= 0):
        agvi, agvj = checkinpreverse(agi, agj)
        if(agvi == 0 and agvj == 0):
            agi, agj = -4, -4
        elif(agvi != -5 and agvj != -5):
            agi, agj = learnagent(world, agvi, agvj)
        else:
            print("\nNot valid")

    if(agi == -5):
        print("\nYou failed!")
    else:
        print("\nYou won!")
