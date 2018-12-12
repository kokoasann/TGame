import CppBridge as cb
import random

def Brain(num,team,f):
    cb.gameData.init(num,team)
    allc = cb.gameData.buddyCount + cb.gameData.enemyCount
    all = cb.gameData.Buddy + cb.gameData.Enemys
    r = random.random()
    i = int(r % allc)
    
    cb.Chase(all[i])
    cb.Atack(all[i])
    cb.End()
    return 1