while(1):
    # Print may or may not require brackets
    print('Do you want to continue ? (y/n)')
    #        vvv=== this is the function to capture raw input from the user
    choice = raw_input()
    # the user input is being stored to a variable named 'choice'
    if choice == 'y': # colon is required
        continue
    else:
        print 'End of Game'
        break
