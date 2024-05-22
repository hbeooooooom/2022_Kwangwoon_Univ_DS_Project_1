# 2022_Kwangwoon_Univ_CE_DS_Project_1
본 프로젝트에서는 이진 탐색 트리와 연결리스트, 그리고 큐 자료구조를 이용하여 간단한 사진 파일 
편집 프로그램을 구현한다. 이 프로그램은 특정 경로에 저장된 사진 파일에 대한 정보를 링크드 리스 
트(Linked List)로 저장한 후, 검색에 용이하게 트리 자료 구조로 저장한다.
이진트리 탐색 알고리즘을 통해 사용자의 입력에 적합한 이미지 파일을 찾아내고, 해당 파일을 읽어 
온다. 이후 큐를 활용하여 각각의 이미지 파일을 읽어오고, 동일한 디렉토리의 command.txt에 입력된 
명령어에 적합하게 이미지를 변형하는 기능을 추가하여 이미지 변형 프로그램을 구현한다. (*본 프로 
젝트에서 사용하는 이미지 파일의 크기[Width, Height]는 고정적이며, 동일하다)

![1](https://github.com/hbeooooooom/2022_Kwangwoon_Univ_DS_Project_1/blob/main/readmdpng/1.png)

# Program implementation
프로그램의 LOAD 명령어를 통해 프로그램이 존재하는 디렉토리 안에 ‘img_files’라는 디렉토리의 이 
미지 목록을 링크드 리스트 구조로 저장한다. 디렉토리에 존재하는 이미지 목록은 ‘filesnumbers.csv’ 
파일에 저장되어 있으며, 파일의 이름과 고유번호(고유번호는 절대 중복되지 않는다)에 대한 정보를 
담고 있다.
LOAD 명령어를 통해 생성된 리스트는 ‘Loaded_LIST’라고 정의하며, 리스트의 각 노드는 파일의 이 
름, 디렉토리 명, 파일의 고유번호에 대한 정보를 갖는다. Loaded_LIST는 노드가 입력되는 순서대로 링 
크드 리스트를 구성한다. 고유번호는 파일의 이름에 따라 할당되는 파일 고유의 숫자로 중복되지 않는 
다. 링크드 리스트로 저장된 Loaded_LIST 구조는 아래와 같다.

![2](https://github.com/hbeooooooom/2022_Kwangwoon_Univ_DS_Project_1/blob/main/readmdpng/2.png)

Loaded_LIST는 ADD 명령어를 통해 새로운 디렉토리에 대한 파일을 탐색하고 파일 및 디렉토리 노 
드를 추가할 수 있다. ADD 명령어를 통해 탐색된 디렉토리는 새로운 리스트를 생성하여 Loaded_LIST 
에 2차원으로 연결한다.
MODIFY 명령어를 통해 Loaded_LIST에 존재하는 노드의 고유번호를 수정할 수 있다. 노드의 고유번 
호를 수정할 때는 기존 노드를 삭제하고 새로운 노드를 추가하는 방식으로 노드의 고유번호를 수정한 
다. 즉, 한번 생성된 노드 내부의 파일의 이름, 디렉토리, 고유번호는 절대 수정하지 않고 노드 자체를 
삭제하고 새로이 연결하는 식으로 동작한다.
Loaded_LIST의 파일 노드는 링크드 리스트 형식으로 연결되어 있어야 하며, 각각의 파일 선행 노드 
(그림에서 ‘img_files’와 ‘new_files’)의 경우 일반적인 리스트 형식으로 연결되도록 한다. Loaded_LIST 
에 존재하는 디렉토리에 대해 LOAD 혹은 ADD가 실행되면 기존에 Loaded_LIST에 존재하는 디렉토리
-2-에 대한 리스트를 삭제하고 새로 리스트를 추가하는 방법으로 Loaded_LIST를 업데이트 한다. 
MOVE 명령어가 입력되면 Loaded_LIST에 존재하는 노드들의 데이터를 트리구조 노드의 데이터로
입력한다. 이때 생성된 트리구조의 자료구조를 ‘Database_BST’라고 한다. 즉, Loaded_LIST의 각각의 노 
드를 트리에 다시 저장하게 되며, 이때 트리에 저장된 노드는 Loaded_LIST에서 삭제(delete)된다.
트리에 노드를 저장할 때에는 Loaded_LIST의 마지막 노드(tail)부터 차례대로 입력한다(그림 2, 그림 
3 참고). Loaded_LIST는 Database_BST(Database_BST는 하나만 존재한다)에 들어가기 전 간단한 수정 
(노드의 고유번호 수정)을 위한 일종의 버퍼 개념의 역할을 하며 따라서 최대 100개의 데이터만 존재 
하도록 한다. 100개 데이터가 넘을 경우 먼저 들어왔던 데이터에 대한 노드를 제거 후 새로운 데이터 
를 추가한다.

![3](https://github.com/hbeooooooom/2022_Kwangwoon_Univ_DS_Project_1/blob/main/readmdpng/3.png)

Database_BST에는 링크드 리스트와 동일하게 파일의 이름, 디렉토리 명, 고유번호로 기록된다. 
Database_BST를 구성하는 각각의 노드들은 아래 연결 규칙에 따라 연결된다.
  1.  부모 노드보다 파일 고유번호가 작은 노드는 왼쪽, 큰 노드는 오른쪽 서브 트리에 위치하도록 
      한다.
  2.  노드를 제거할 때, 양쪽 자식 노드가 모두 존재할 경우에는 왼쪽 자식 노드 중 가장 큰 노드를 
      제거되는 노드 위치로 이동시킨다.
      
Database_BST는 이러한 연결 규칙을 통해 보다 빠른 검색을 가능하도록 한다. 즉, 파일 고유번호 기 
반의 검색 속도를 강화한다. Database_BST의 최대 크기는 300개 노드이며, 이 이상의 노드가 배치되 
었을 때는 트리내 고유 번호가 낮은 노드부터 순차적으로 삭제하도록 한다.
이렇게 트리 구조에 저장된 노드에 대해서 사용자가 편집할 파일을 지정하게 하는 SELECT 명령어를
구현한다. SELECT 명령어는 파일의 고유 번호를 바탕으로 파일을 전위 순회 알고리즘을 통해 탐색하 
여 찾아내고, 편집을 위해 선택하도록 한다.
파일의 검색을 위해 SEARCH 명령어 또한 구현한다. 파일의 이름이 3글자 이상의 문장으로 구현되 
어 있음으로, 보이어 무어 알고리즘을 통해 Database_BST 트리에 존재하는 파일 이름에 대해 탐색한 
다. 탐색 방법은 아래와 같다.
  1. 파일의 이름기반 검색을 위해 트리를 Iterative post-order(반복문을 이용한 post-order, 재귀 
  함수 사용금지) 방식으로 순회하며 큐에 트리 노드 안에 존재하는 파일이름과 고유번호에 대 
  한 정보를 담는다.
  2.  모든 노드에 대한 정보가 저장되었다면 순차적으로 POP을 진행하며 사용자가 SEARCH 명령 
  어에 검색한 단어가 파일 명에 있는지 검색한다.
  3.  단어가 존재하는 경우 해당 노드의 파일명 전체와 파일 고유번호를 출력한다.
  4.  검색이 완료된 이후의 큐는 반드시 비어 있어야 한다.


![4](https://github.com/hbeooooooom/2022_Kwangwoon_Univ_DS_Project_1/blob/main/readmdpng/4.png)

보이어 무어 알고리즘은 특정 문자열에서 원하는 패턴을 찾는 알고리즘으로 문장과 같은 character 
를 가진 문장 패턴만을 비교해가며 본래 문장에서 찾고자 하는 패턴을 찾아낸다. 해당 방식을 통한 탐 
색은 탐색 속도를 개선할 수 있다.

![5](https://github.com/hbeooooooom/2022_Kwangwoon_Univ_DS_Project_1/blob/main/readmdpng/5.png)

최종적으로 SELECT 명령어를 통해 선택된 파일에 대해서 주어진 코드를 이용해 이미지 파일을 읽어 
와서 아래와 같은 이미지 편집 프로그램을 구현한다.
  l  이미지의 점대칭
    - 각 이미지 픽셀을 알맞게 Stack 구조에 순서대로 입력하고(Push) 후입선출(POP)하여 이 
    미지를 점대칭으로 뒤집는다. (단, 각 픽셀에 대한 정보 할당은 반드시 처음 PUSH한 픽 
    셀부터 다시 할당한다)
  l  이미지의 밝기 조정
    - 각 이미지 픽셀을 알맞게 Queue에 순서대로 입력하고(Push) 선입선출(POP) 하며 각 픽 
    셀의 값에 특정 숫자를 더해 이미지를 밝게 만든다. (단, 이미 밝기가 최대인 픽셀에 대해 
    서는 최대 값(255)을 할당한다. 특정 숫자만큼 더하지 못할 경우 더할 수 있는 만큼 최대 
    한 더한다.)
  l  이미지의 크기 조정
    - 입력된 이미지의 크기를 4분의 1로 축소하는 구현을 진행한다. 4개의 셀의 평균값을 구 
    해 하나의 셀에 입력하는 방식으로 구현한다. (제공되는 이미지의 [Width, Height]는 짝 
    수이다.)

![6](https://github.com/hbeooooooom/2022_Kwangwoon_Univ_DS_Project_1/blob/main/readmdpng/6.png)

작업된 결과는 반드시 이미지 파일로 지정한 디렉토리(Result 디렉토리)에 주어진 코드를 이용하여 
저장되어야 하며, EXIT 명령어를 통해 프로그램을 종료할 수 있도록 한다. 프로그램 종료 이후 모든 메 
모리는 free 되어야 한다.