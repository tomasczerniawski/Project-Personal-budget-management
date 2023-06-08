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

  
