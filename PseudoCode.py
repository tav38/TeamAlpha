#Set the number of rounds to win
num2win = 99

#Generate that many rounds of actions
for i in range(num2win):
    move = random(0,2)
    
    #Guard Coming - User must be quiet
    if move = 0:
        Read Guard Coming Command
        activate microphone
        indicate microphone about to turn on
            
        #Give user time to process command
        while time_for_command:
            if Crack the Code/Sneak Around triggered:
                Game Ends
        
        #See if user is quiet
        indicate microphone turned on
        if quiet:
            success cue
            break
        else:
            failure cue
            Game Ends

            
    #Crack the Code - Device will read out numbers and the user must type it into the keypad
    elif move = 1:
        Read Crack the Code Command
        
        select random code numbers
        Read out secret code numbers
        
        while time_for_command:
            if Sneak Around triggered:
                failure cue
                game ends
                
            elif code wrong:
                failure cue
                game ends
                
            elif code entered correctly:
                success cue
                break
        
        if action uncomplete:
            failure cue
            game ends
        
    #Sneak Around - User must press the button without triggering the “trip wire” lasers
    else:  
        Read Sneak Around Command
        
        indicate button to press
        
        while time_for_command:
            if Crack the Code triggered:
                failure cue
                game ends
            elif laser hit or wrong button pressed:
                failure cue
                game ends
            elif correct button hit:
                success cue
                break
        
        if action uncomplete:
            failure cue
            game ends
    
    Decrement time_for_command
    

Read Open Vault Command
Unlock Vault

if user spins wheel:
    success cue
    game ends w/ win
else:
    failure cue
    game ends

