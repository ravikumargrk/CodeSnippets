import os,sys
sys.path.append(os.getcwd())
from matrixmultiply import fun_matrixmultiply
import pytest


@pytest.mark.parametrize('s1, s2, result',[	
([[1,3],[2,4],[2,5]], [[1,3,2,2], [2,4,5,1]], [[7, 15, 17, 5], [10, 22, 24, 8], [12, 26, 29, 9]]),
([[1],[2,4],[2,5]], [[1,3,2,2], [2,4,5,1]], None),
([[1,3,5],[2,4,6],[2,5,7]], [[1,3,2,2], [2,4,5,1]], None),
([[1,3],[2,4]], [[1,3,2,2], [2,4,5,1]], [[7, 15, 17, 5], [10, 22, 24, 8]])
])
def test_fun_matrixmultiply(s1, s2, result):
    assert fun_matrixmultiply(s1, s2) == result

