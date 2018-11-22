import CppBridge as cb

def Brain(MeNum,MeTeam):
    #cb.gameData.init()
    ME = cb.gameData.me
    mon = cb.gameData.GetEnemyHighHP()
    
    cb.Chase(mon)
    cb.Atack(mon)
    if ME.HP < 3:
        cb.Leave(mon)
    cb.End()
    return cb.actions

