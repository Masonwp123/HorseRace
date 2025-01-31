# Horse Race
Get ready... To LOSE!!!

## Constants
```
Make a constant int NUM_HORSES
Make a constant int TRACK_LENGTH
```

## Functions

**advance**
will only advance if ran is >= 0.5 (so 1/2 chance to move)
```
  horseArray is array of int
  horseNum is int
  function advance (horseNum, horseArray): 
    float ran = randomfloat(0.0, 2.0)
    horseArray[horseNum] += round(ran)
```

**printLane**
```
  horseArray is array of int
  horseNum is int
  function printLane (horseNum, horseArray):
    horsePos = horseArray[horseNum]
    for 0 to TRACK_LENGTH:
      if loop index is equal to horseNum:
        print horseNum
        continue
      print "."
```

**isWinner**
```
  horseArray is array of int
  horseNum is int
  function isWinner (horseNum, horseArray):
    horsePos = horseArray[horseNum]
    if horsePos is greater than or equal to TRACK_LENGTH - 1:
        return true
    return false
```

**main**
```
  function main ():
    set keepGoing to true
    
    while keepGoing:
      for each horse in array:
        call advance for horse
        call printLane for horse
        if call isWinner for horse:
          set keepGoing to false
        ask user for input for next turn
    for each horse in array:
      if call isWinner for horse:
        print end message for winningHorse
        return
```

