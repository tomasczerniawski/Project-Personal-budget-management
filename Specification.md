# Personal Budget Management

Projekt ma na celu pomóc użytkownikom w zarządzaniu swoim budżetem osobistym. Projekt będzie zawierał funkcje, takie jak dodawanie, edytowanie i usuwanie wydatków i dochodów oraz umożliwi użytkownikom śledzenie swojego budżetu i generowanie raportów.

## Schematy

### Expense

Opis: Reprezentuje wydatek i zawiera następujące pola:

- `name` (string): Nazwa lub opis wydatku.
- `expense_id` (int): numer identyfikacji.
- `amount` (float): Kwota wydatku.
- `date` (string): Data wydatku w formacie YYYY-MM-DD.

### Income

Opis: Reprezentuje dochód i zawiera następujące pola:

- `name` (string): Nazwa lub opis dochodu.
- `income_id` (int): numer identyfikacji.
- `amount` (float): Kwota dochodu.
- `date` (string): Data dochodu w formacie YYYY-MM-DD.

## Funkcje

1. Dodaj wydatek lub dochód:
   - Parametry:
     - `expense` (Expense): Obiekt reprezentujący wydatek.
     - `income` (Income): Obiekt reprezentujący dochód.
     - `amount` (float): Kwota wydatku lub dochodu.
   - Opis: Dodaje nowy wydatek lub dochód do budżetu.

2. Przeglądaj budżet:
   - Opis: Wyświetla wszystkie wydatki i dochody w budżecie.

3. Wyszukaj w budżecie:
   - Parametry:
     - `keyword` (string): Słowo kluczowe do wyszukania.
   - Opis: Wyszukuje wydatki lub dochody zawierające podane słowo kluczowe w nazwie lub kategorii.

4. Generuj raporty:
   - Opis: Generuje raporty na temat budżetu, np. podsumowanie wydatków w poszczególnych kategoriach.

5. Funkcja przypominania o planowanych wydatkach:
   - Opis: Wysyła powiadomienia użytkownikowi o planowanych wydatkach w określonym czasie lub dniu.

6. Zapisywanie celów finansowych:
   - Parametry:
     - `goal` (string): Opis celu finansowego.
     - `amount` (float): Kwota celu finansowego.
   - Opis: Zapisuje cel finansowy, który użytkownik chce osiągnąć, wraz z określoną kwotą. Cel finansowy może dotyczyć oszczędzania na konkretny cel, np. wakacje, samochód, czy też spłaty długu. Ta funkcja umożliwia śledzenie postępu w osiąganiu celu finansowego.
  
