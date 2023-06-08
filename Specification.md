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

:page_facing_up: AdjuvantMethods.cpp: Plik źródłowy zawierający pomocnicze metody.

:page_facing_up: AdjuvantMethods.h: Plik nagłówkowy zawierający deklaracje pomocniczych metod.

:page_facing_up: Budget.cpp: Plik źródłowy zawierający implementację klasy Budget.

:page_facing_up: Budget.h: Plik nagłówkowy zawierający deklarację klasy Budget.

- `Date.cpp`: Plik źródłowy zawierający implementację klasy Date.
- `Date.h`: Plik nagłówkowy zawierający deklarację klasy Date.

- `Expense.cpp`: Plik źródłowy zawierający implementację klasy Expense.
- `Expense.h`: Plik nagłówkowy zawierający deklarację klasy Expense.

- `ExpensesFile.cpp`: Plik źródłowy zawierający implementację klasy ExpensesFile.
- `ExpensesFile.h`: Plik nagłówkowy zawierający deklarację klasy ExpensesFile.

- `Finance.cpp`: Plik źródłowy zawierający implementację klasy Finance.
- `Finance.h`: Plik nagłówkowy zawierający deklarację klasy Finance.

- `FinanceManager.cpp`: Plik źródłowy zawierający implementację klasy FinanceManager.
- `FinanceManager.h`: Plik nagłówkowy zawierający deklarację klasy FinanceManager.

- `Income.cpp`: Plik źródłowy zawierający implementację klasy Income.
- `Income.h`: Plik nagłówkowy zawierający deklarację klasy Income.

- `IncomesFile.cpp`: Plik źródłowy zawierający implementację klasy IncomesFile.
- `IncomesFile.h`: Plik nagłówkowy zawierający deklarację klasy IncomesFile.

- `Markup.cpp`: Plik źródłowy zawierający implementację klasy Markup.
- `Markup.h`: Plik nagłówkowy zawierający deklarację klasy Markup.

- `User.cpp`: Plik źródłowy zawierający implementację klasy User.
- `User.h`: Plik nagłówkowy zawierający deklarację klasy User.

- `UserManager.cpp`: Plik źródłowy zawierający implementację klasy UserManager.
- `UserManager.h`: Plik nagłówkowy zawierający deklarację klasy UserManager.

- `UsersFile.cpp`: Plik źródłowy zawierający implementację klasy UsersFile.
- `UsersFile.h`: Plik nagłówkowy zawierający deklarację klasy UsersFile.

- `XmlFile.cpp`: Plik źródłowy zawierający implementację klasy XmlFile.
- `XmlFile.h`: Plik nagłówkowy zawierający deklarację klasy XmlFile.

- `main.cpp`: Plik źródłowy zawierający funkcję main().


  
  
  
  
  
  
