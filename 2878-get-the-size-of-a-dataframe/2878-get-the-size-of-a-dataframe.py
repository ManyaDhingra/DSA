import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    a = players.shape
    return list(a)
    