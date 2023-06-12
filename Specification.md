# Personal Budget Management

Projekt ma na celu pomóc użytkownikom w zarządzaniu swoim budżetem osobistym. Projekt będzie zawierał funkcje, takie jak dodawanie, edytowanie i usuwanie wydatków i dochodów oraz umożliwi użytkownikom śledzenie swojego budżetu i generowanie raportów.

## Opisanie struktur

### BinaryTreeNode<T>

Klasa reprezentująca węzeł w drzewie binarnym. Ma następujące pola:

- `data` (typ `T`): Przechowuje dane reprezentujące przychód lub wydatek.
- `left` (typ `BinaryTreeNode*`): Wskaźnik na lewe poddrzewo.
- `right` (typ `BinaryTreeNode*`): Wskaźnik na prawe poddrzewo.

### BinaryTree<T>

Klasa reprezentująca drzewo binarne. Ma następujące pola:

- `root` (typ `BinaryTreeNode<T>*`): Wskaźnik na korzeń drzewa.

### FinanceManager

Klasa zarządzająca finansami. Ma następujące pola:

- `CURRENT_USER_ID` (typ `const int`): Identyfikator bieżącego użytkownika.
- `incomesBinaryTree` (typ `BinaryTree<Income>`): Drzewo binarne przechowujące przychody.
- `expensesBinaryTree` (typ `BinaryTree<Expense>`): Drzewo binarne przechowujące wydatki.
- `incomesFile` (typ `IncomesFile`): Obiekt obsługujący plik z danymi dotyczącymi przychodów.
- `expensesFile` (typ `ExpensesFile`): Obiekt obsługujący plik z danymi dotyczącymi wydatków.
- `date` (typ `Date`): Obiekt reprezentujący datę.
- `totalIncome` (typ `float`): Suma przychodów w określonym okresie.
- `totalExpense` (typ `float`): Suma wydatków w określonym okresie.
- Pozostałe pola zawierające metody i funkcje.

## Typy parametrów w strukturach

W powyższych strukturach używane są następujące typy parametrów:

- `T`: Jest to parametr szablonu, który reprezentuje typ danych przechowywanych w drzewie binarnym. W przypadku `incomesBinaryTree` jest to typ `Income`, a w przypadku `expensesBinaryTree` jest to typ `Expense`.
- `Income`: Klasa reprezentująca przychód.
- `Expense`: Klasa reprezentująca wydatek.
- `IncomesFile`: Klasa obsługująca plik z danymi dotyczącymi przychodów.
- `ExpensesFile`: Klasa obsługująca plik z danymi dotyczącymi wydatków.
- `Date`: Klasa reprezentująca datę.
  
  
  # Język programowania: C++
  Wybrałem język C++  do tego projektu z kilku powodów:
  - Obiektowość: C++ jest językiem programowania obiektowego, co umożliwia strukturalne i modułowe projektowanie aplikacji. Możemy używać klas i obiektów, aby logicznie grupować związane ze sobą funkcje i dane.
  - Biblioteki i narzędzia: oferuje szeroki zakres bibliotek i narzędzi, które mogą być przydatne przy tworzeniu projektu zarządzania finansami. Na przykład, możemy korzystać z bibliotek do obsługi plików, struktur danych czy obliczeń matematycznych. 
  - Poruwnając z innymi językami programowania pracowałem z C++ najwięcej
  
  Biorąc pod uwagę te czynniki, C++ jest dobrym wyborem do projektu zarządzania finansami.
  
  
  # Opis Struktury (Organizacja katalogowa) i Nazwy Plików

W projekcie Finansowy zastosowano następującą strukturę organizacyjną katalogów i nazw plików:

## Katalog główny i jedyny

- `src/`: Katalog zawierający pliki źródłowe projektu.

## Katalog src/

:page_facing_up: `AdjuvantMethods.cpp:` Plik źródłowy zawierający pomocnicze metody.

:page_facing_up:  `AdjuvantMethods.h:` Plik nagłówkowy zawierający deklaracje pomocniczych metod.
  
:scroll:  **Budget.cpp:** Plik źródłowy zawierający implementację klasy Budget.

:scroll: **Budget.h:** Plik nagłówkowy zawierający deklarację klasy Budget.

:page_facing_up: `Date.cpp:` Plik źródłowy zawierający implementację klasy Date.
  
:page_facing_up: `Date.h:` Plik nagłówkowy zawierający deklarację klasy Date.

:scroll: **Expense.cpp:** Plik źródłowy zawierający implementację klasy Expense.
  
:scroll: **Expense.h:** Plik nagłówkowy zawierający deklarację klasy Expense.

:page_facing_up: `ExpensesFile.cpp:` Plik źródłowy zawierający implementację klasy ExpensesFile.
  
:page_facing_up: `ExpensesFile.h:` Plik nagłówkowy zawierający deklarację klasy ExpensesFile.

:scroll: **Finance.cpp:** Plik źródłowy zawierający implementację klasy Finance.
  
:scroll: **Finance.h:** Plik nagłówkowy zawierający deklarację klasy Finance.

:page_facing_up: `FinanceManager.cpp:` Plik źródłowy zawierający implementację klasy FinanceManager.
  
:page_facing_up: `FinanceManager.h:` Plik nagłówkowy zawierający deklarację klasy FinanceManager.

:scroll:  **Income.cpp:** Plik źródłowy zawierający implementację klasy Income.
  
:scroll:  **Income.h:** Plik nagłówkowy zawierający deklarację klasy Income.

:page_facing_up:  `IncomesFile.cpp:` Plik źródłowy zawierający implementację klasy IncomesFile.
  
:page_facing_up:  `IncomesFile.h:` Plik nagłówkowy zawierający deklarację klasy IncomesFile.

:scroll:  **Markup.cpp:** Plik źródłowy zawierający implementację klasy Markup.
  
:scroll:  **Markup.h:** Plik nagłówkowy zawierający deklarację klasy Markup.

:page_facing_up:  `User.cpp:` Plik źródłowy zawierający implementację klasy User.
  
:page_facing_up:  `User.h:` Plik nagłówkowy zawierający deklarację klasy User.

:scroll: **UserManager.cpp:** Plik źródłowy zawierający implementację klasy UserManager.
  
:scroll: **UserManager.h:** Plik nagłówkowy zawierający deklarację klasy UserManager.

:page_facing_up:  `UsersFile.cpp:` Plik źródłowy zawierający implementację klasy UsersFile.
  
:page_facing_up:  `UsersFile.h:` Plik nagłówkowy zawierający deklarację klasy UsersFile.

:scroll: **XmlFile.cpp:** Plik źródłowy zawierający implementację klasy XmlFile.
  
:scroll: **XmlFile.cpp:** Plik nagłówkowy zawierający deklarację klasy XmlFile.

:page_facing_up:  `main.cpp:` Plik źródłowy zawierający funkcję main().


  
  # Algorytmy i struktury danych które będą używane w projekcie

W pliku BinaryTree.h została zaimplementowana struktura danych drzewa binarnego (Binary Tree) oraz odpowiednie algorytmy operujące na tej strukturze.

## Struktura danych

### BinaryTreeNode
Klasa `BinaryTreeNode` reprezentuje węzeł drzewa binarnego. Posiada trzy pola: 
  
- `data:` przechowujące wartość węzła
- `left` i `right`, wskazujące na lewe i prawe poddrzewo.

### BinaryTree
Klasa `BinaryTree` reprezentuje drzewo binarne. Posiada pole
-`root:` które wskazuje na korzeń drzewa. Klasa udostępnia metody do wstawiania węzłów, przeprowadzania in-order traversal (przechodzenia drzewa w porządku rosnącym) oraz wyszukiwania węzłów na podstawie podanego słowa kluczowego.

## Algorytmy

### insertRecursive
- Metoda `insertRecursive` to algorytm rekurencyjny do wstawiania węzłów do drzewa binarnego. Wyszukuje odpowiednie miejsce w drzewie, aby wstawić nowy węzeł na podstawie wartości klucza. Jeśli węzeł jest mniejszy od bieżącego węzła, zostaje wstawiony do lewego poddrzewa; w przeciwnym razie zostaje wstawiony do prawego poddrzewa.
  
  ![image](https://www.codesdope.com/staticroot/images/ds/bst9.gif)
  
  **W mym kodzie:**
 - Obiekty są porównywane na podstawie wartości ich ceny (Amount). Jeśli Amount danego obiektu jest mniejsze niż Amount bieżącego węzła, to obiekt jest wstawiany do lewego poddrzewa. W przeciwnym przypadku, jeśli Amount jest większe lub równe Amount bieżącego węzła, obiekt jest wstawiany do prawego poddrzewa. W ten sposób drzewo binarne jest konstruowane w taki sposób, że wartości Amount są uporządkowane rosnąco w drzewie.


### inOrderTraversalRecursive
- Metoda `inOrderTraversalRecursive` to algorytm rekurencyjny do in-order traversal drzewa binarnego. Przechodzi przez drzewo w porządku rosnącym, odwiedzając najpierw lewe poddrzewo, następnie bieżący węzeł i na koniec prawe poddrzewo. W tym przypadku, wartość opisująca węzeł jest wypisywana na standardowym wyjściu.
  
  ![image](https://lh3.googleusercontent.com/QRTgAbTK-54jPLU87RN4OAXWlBu1WR36LyaANNQ_Pg0N2gKmM0k_30h5S68Dwm_2qledVGQd5Byltj16KO3J5ufZs1ipixS4DKpHTRITXDiHajiLXEjf_sY7Id7e8G7r4mhBbANn)
  
### searchRecursive
- Metoda `searchRecursive` to algorytm rekurencyjny do wyszukiwania węzłów w drzewie binarnym na podstawie podanego słowa kluczowego. Przeszukuje drzewo, porównując opisy węzłów z podanym słowem kluczowym. Jeśli węzeł jest znaleziony, zostaje zwrócony. W przeciwnym razie, algorytm rekurencyjnie przeszukuje lewe i prawe poddrzewo.

  ![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/83f2302b-2e6e-40b2-b90f-e401ae3ec8d0)

    
  
  **W mym kodzie:**
  
- Metoda "search" przyjmuje parametr "keyword", który reprezentuje opis, którego szukamy w drzewie. Metoda wywołuje funkcję "searchRecursive" przekazując jej korzeń drzewa ("root") oraz poszukiwane "keyword". Funkcja "searchRecursive" rozpoczyna od sprawdzenia, czy bieżący węzeł jest pusty lub czy jego opis odpowiada poszukiwanemu "keyword". Jeśli tak, zwraca ten węzeł.

- Jeśli opis bieżącego węzła nie odpowiada poszukiwanemu "keyword", funkcja rekurencyjnie wywołuje się dla lewego i prawego poddrzewa. Jeśli znaleziono węzeł w lewym poddrzewie, zwraca ten węzeł. W przeciwnym razie, wywołuje się dla prawego poddrzewa.

- W przypadku, gdy nie zostanie znaleziony żaden węzeł o odpowiadającym opisie "keyword", funkcja "search" zwraca nullptr.

  
  # W pliku FinanceManager.cpp
  
 ## Algorytmy
  
 ### Bubble Sort
- Bubble Sort (sortowanie bąbelkowe) to prosty algorytm sortowania, który porównuje sąsiednie elementy i zamienia je miejscami, jeśli są w niewłaściwej kolejności. Algorytm wykonuje te operacje w pętli, przechodząc przez listę wielokrotnie, aż lista będzie posortowana.

  ![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/beff2f5c-7fda-4af1-b899-b777127afd25)

  Podsumowując, w tym kodzie Bubble Sort jest używany do sortowania danych w drzewie binarnym. Algorytm porównuje i zamienia miejscami węzły na podstawie ich wartości przychodów.
  
  # Funkcje:
  
### Ta funkcja przedstawia menu łogowania programu
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/281e3ade-4f49-476a-94ea-18deeb2ceb9d)






- `Main Menu:` Funkcja wyświetla główne menu programu, gdzie użytkownik może wybrać jedną z trzech opcji:

- Sign up: Ta opcja pozwala użytkownikowi zarejestrować nowe konto. Po wybraniu tej opcji, użytkownik zostaje poproszony o podanie swoich danych rejestracyjnych, takich jak nazwa użytkownika i hasło. Następnie te dane są przetwarzane i zapisywane w XML filu gdzie jest także nadawany numer identyfikacyjny (UserId), umożliwiając użytkownikowi korzystanie z programu.

- Sign in: Ta opcja umożliwia zalogowanie się do istniejącego konta. Po wybraniu tej opcji, użytkownik zostaje poproszony o podanie swojej nazwy użytkownika i hasła w celu uwierzytelnienia. Jeśli dane logowania są poprawne, użytkownik uzyskuje dostęp do pełnej funkcjonalności programu.

- Exit: Ta opcja umożliwia użytkownikowi zakończenie działania programu. Po wybraniu tej opcji program zostaje zamknięty i zakończony.
  
### Glówna menu projektu Personal Budget Managment
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/2ed0f216-047a-4f2b-a09d-96b7e755ad7d)
  
## Fumkcja Dodać dochód (wybór nr. 1)
  
### Add income
  
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/c9a0d5d3-443a-4722-842b-fd823d8b4c6f)

  - Opcja "Add income" pozwala użytkownikowi dodać nowy przychód do systemu. Po wybraniu tej opcji, użytkownik jest prowadzony przez proces wprowadzania danych dotyczących przychodu, takich jak data, przedmiot i kwota, przepisane automatychnie do kądego dochodu jest identyfikator użytkownika, i identyfikator dochodu. Następnie funkcja wywołuje funkcję "addIncomeToXmlFile" w celu dodania przychodu do pliku XML. Jeśli dodawanie przebiegnie pomyślnie, wyświetlany jest komunikat potwierdzający. Po zakończeniu użytkownik jest proszony o naciśnięcie dowolnego klawisza w celu kontynuacji.
  
## Fumkcja Dodać wydatek (wybór nr. 2)

### Add expense
  
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/be705b86-d220-4382-8f20-1caf45bc4c22)

  - Opcja "Add expense" pozwala użytkownikowi dodać nowy wydatek do systemu i pracuje wten sam sposób jak "Add income".
  
## Funkcja zobacz budżet bieżącego miesiąca (wybór nr. 3)
  
### View current month's balance
  
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/c7e3aa5a-61fb-4698-bad5-1a010649c8bd)

 - Funkcja "viewCurrentMonthBalance" służy do wyświetlania bilansu bieżącego miesiąca. Najpierw oblicza minimalną i maksymalną datę dla bieżącego miesiąca na podstawie aktualnej daty systemowej. Wyświetlane są informacje dotyczące przychodów i wydatków bieżącego miesiąca oraz podsumowanie.

- Funkcja wywołuje funkcję "viewSelectedIncomes" w celu wyświetlenia przychodów dla określonego zakresu dat (od minDate do maxDate) z wykorzystaniem struktury drzewa binarnego. Następnie wywoływana jest funkcja "viewSelectedExpenses" dla wyświetlenia wydatków bieżącego miesiąca.

- Funkcja viewSelectedIncomes" przechodzi przez drzewo binarne przychodów w porządku inorder przy użyciu stosu. Dla każdego węzła, sprawdzane jest, czy data przychodu mieści się w określonym zakresie dat (minDate do maxDate). Jeśli tak, to szczegóły przychodu (np. nazwa i kwota) są wyświetlane na konsoli.

- Funkcja kończy działanie, gdy przejdzie przez wszystkie węzły drzewa dochodów i wydatków w ten sam sposób lub gdy stos jest pusty.
  
## Fumkcja zobacz budżet wybranego okresu (wybór nr. 4)
  
### View balance of the selected period
  
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/efc3be6e-9470-413b-959d-a6aa9c95cc29)

- Funkcja "viewBalanceOfSelectedPeriod" służy do wyświetlania bilansu dla wybranego okresu. Użytkownik jest proszony o podanie daty początkowej i daty końcowej okresu, który chce przeglądać. Następnie funkcja oblicza minimalną i maksymalną datę dla tego okresu.
- Pracuje wten sam sposób ja funkcja poprzednia tyko użytkownik tu podaje okres przepatrywanego budżetu
  
## Fumkcja wyświetl wszystkie dochody/wydatki (wybór nr. 5/6)
  
### View all incomes/expenses:
  
  - Zlanczam te dwie opcje bo pracują jednakowo.
  
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/26c3e90b-6f09-46fd-bbdd-0a5785a55866)

- Funkcja "viewAllIncomes" służy do wyświetlania wszystkich przychodów. Na początku funkcja wywołuje funkcję "viewIncome", przekazując jej korzeń drzewa binarnego "incomesBinaryTree". 

- Funkcja "copyBinaryTree" kopiuje drzewo binarne, które jest przekazywane jako argument "node". Tworzony jest nowy węzeł o takiej samej wartości, a następnie rekurencyjnie kopiowane są lewe i prawe poddrzewa.   Jest używana dlatego aby uniknąć modyfikowania oryginalnego drzewa, tworzona jest kopia, na której wykonywane są te operacje.

- Funkcja "deleteBinaryTree" służy do usuwania drzewa binarnego. Rekurencyjnie usuwane są lewe i prawe poddrzewa, a następnie usuwany jest węzeł.

- Funkcja "viewIncome" inicjuje wyświetlanie przychodów. Na początku tworzy kopię oryginalnego drzewa przychodów za pomocą funkcji "copyBinaryTree". Następnie wyświetla użytkownikowi opcje sortowania przychodów, takie jak sortowanie według daty (najnowsze lub najstarsze) lub sortowanie według ceny (najtańsze lub najdroższe). Wybór użytkownika jest przechowywany w zmiennej "choice".

- W zależności od wyboru użytkownika, wyświetlane są przychody w określonej kolejności sortowania. Funkcje takie jak "viewIncomeByDateNewest", "viewIncomeByDateOldest", "sortIncomesByAmount", "displayIncomesByAmount" i "viewIncomeByPriceMostExpensive" są wywoływane w zależności od wyboru użytkownika.

- Funkcje "viewIncomeByDateNewest" i "viewIncomeByDateOldest" służą do wyświetlania przychodów posortowanych według daty, z najnowszymi lub najstarszymi na początku. Wykorzystują one stos do przechodzenia drzewa binarnego w odwrotnej kolejności (prawo, korzeń, lewo) i przechowują posortowane przychody w kontenerze "sortedIncomes"

- Funkcja "countNodes" służy do zliczania liczby węzłów w drzewie binarnym. Rekurencyjnie obliczana jest liczba węzłów w lewym i prawym poddrzewie, a następnie dodawana jest jednostka za aktualny węzeł.

- Funkcja "sortIncomesByAmount" sortuje przychody według ceny, wykorzystując algorytm sortowania bąbelkowego. Najpierw obliczana jest liczba węzłów w poddrzewie, a następnie porównywane są sąsiednie węzły i zamieniane, jeśli cena jednego jest większa od drugiego. Ta procedura jest powtarzana dla wszystkich węzłów.

- Funkcja "displayIncomesByAmount" wyświetla przychody według ceny, korzystając z porządku inorder (lewo, korzeń, prawo). Rekurencyjnie wywoływana jest dla lewego poddrzewa, wyświetlany jest aktualny przychód, a następnie rekurencyjnie wywoływana jest dla prawego poddrzewa.  

  
## Fumkcja Szukaj w budżecie (wybór nr. 7)
  
### Search in budget
  
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/ef741b7b-7b99-476e-a517-2c7a573fa1e1)
  
 - Funkcje searchIncomesAndExpenses, searchIncomeByItemRecursive i searchExpenseByItemRecursive służą do wyszukiwania przychodów i wydatków na podstawie podanego słowa kluczowego.

- Funkcja searchIncomesAndExpenses inicjalizuje proces wyszukiwania. Funkcja wywołuje dwie inne funkcje rekurencyjne: searchIncomeByItemRecursive i searchExpenseByItemRecursive. 

- Funkcje searchIncomeByItemRecursive i searchExpenseByItemRecursive rekurencyjnie przeszukują drzewa binarne przychodów i wydatków w poszukiwaniu węzłów, których element "item" jest zgodny z podanym słowem kluczowym. Jeśli takie węzły są znalezione, wywoływana jest funkcja displayIncome lub displayExpense, która wyświetla szczegóły dotyczące znalezionego przychodu lub wydatku. Parametr resultsFound jest używany do śledzenia, czy znaleziono jakiekolwiek wyniki.

## Fumkcja Generuj raport (wybór nr. 8)
  
### Generate report
  
![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/a3d1af62-022a-4c03-9e76-b3d50177422c)

 -Funkcje generateMonthlyIncomeChart, countMonthlyIncomes i countMonthlyExpenses służą do generowania raportu miesięcznego dotyczącego budżetu.

- Funkcja generateMonthlyIncomeChart inicjalizuje proces generowania raportu. Na początku użytkownik jest proszony o podanie daty początkowej i końcowej okresu, który chce przeglądać. Następnie funkcja wywołuje inne funkcje, takie jak viewSelectedIncomes, viewSelectedExpenses, calculateTotalIncome i calculateTotalExpense, które wyświetlają wybrane przychody i wydatki oraz obliczają łączny przychód i wydatek w określonym okresie.

- Następnie funkcja generuje wykres miesięcznych budżetu w określonym okresie. Tworzy wektor monthlyIncomes, w którym przechowywane są kwoty przychodów dla każdego miesiąca. Następnie funkcja iteruje po węzłach przychodów i sumuje kwoty przychodów dla każdego miesiąca. Wykres jest prezentowany za pomocą znaków "#" i "---" w zależności od kwoty przychodów.

- Na koniec funkcja wyświetla podsumowanie wybranego okresu, zawierające łączny przychód, łączny wydatek i budżetu miesiąca.

- Funkcje countMonthlyIncomes i countMonthlyExpenses są funkcjami pomocniczymi, które rekurencyjnie przechodzą przez drzewa binarne przychodów i wydatków, obliczając sumy przychodów i wydatków dla poszczególnych miesięcy w określonym okresie. Znalezione kwoty są przechowywane w wektorach monthlyIncomes i monthlyExpenses.

## FumkcjaGeneruj losowy budżet (wybór nr. 9)
  
### Generate random budget
  
  ![image](https://github.com/tomasczerniawski/Project-Personal-budget-management/assets/115027239/c598b766-4fa5-425b-ae8f-41006c92375c)
  
- Użytkownik jest proszony o podanie daty początkowej i końcowej okresu,  podanie minimalnej i maksymalnej kwoty i liczbe wydaków i dochodów generowanych
Generowana jest losowa kwota w podanym zakresie przy użyciu funkcji "rand()" oraz operacji matematycznych.

- Generowanie losowej daty w podanym zakresie opiera się na wykorzystaniu minimalnych i maksymalnych wartości roku, miesiąca i dnia, a następnie korzysta z funkcji "rand()" do wygenerowania losowych wartości dla tych składników daty.
  
- Dodatkowo, funkcja korzysta z drzew binarnych (incomesBinaryTree i expensesBinaryTree) do przechowywania wygenerowanych przychodów i wydatków. W przypadku generowania przychodu, tworzony jest obiekt klasy "Income" i dodawany do incomesBinaryTree. W przypadku generowania wydatku, tworzony jest obiekt klasy "Expense" i dodawany do expensesBinaryTree

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
