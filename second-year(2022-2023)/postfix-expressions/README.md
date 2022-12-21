# Методы программирования 3: Вычисление арифметических выражений (стеки)

## Требования к лабораторной работе
В рамках лабораторной работы ставятся задачи реализации программ, обеспечивающих поддержку стеков, и разработки программных средств, производящих обработку арифметических выражений, включая проверку правильности записи выражения, перевод в постфиксную форму и вычисление результата.
    
## Структура
* TStack.h – шаблонный класс стек.
* Table.h - шаблонный класс словарь, реализованный на AA-дереве.
* ExpressionValidator.h, ExpressionValidator.cpp - класс, проверяющий корректность выражения.
* ExpressionValidator.h, ExpressionSeparator.cpp - класс, разбивающий выражения на токены.
* PostfixExpessions.h, PostfixExpessions.cpp - класс, конвертирующий выражение в постфиксную форму и считающий значение постфиксного выражения.
* test.cpp - модуль программ тестирования.

## Спецификации классов
### 1.Tstack
* Поля:
```cpp
private:
    size_t top; // индекс вершины стека
    size_t memSize; // размер выделенной памяти
    Type* data; //  указатель на массив элементов
    bool isEmpty;
```
* Методы:
```cpp
public:
    TStack(size_t size = 10); // конструктор
    TStack(const TStack& stack); // конструктор копирования
    TStack(TStack&& stack); // конструктор перемещения
    ~TStack(); // деструктор
    void Risize() // перевыделяет память
    void Push(const Type& element) // добавляет элемент в стек
    Type Top() // возвращает верхний элемент стека
    Type Pop() // возвращает верхний элемент стека, с удалением возвращаемого значения из стека
    bool IsEmpty() // возвращает true, если стек не пустой
```
### 2.Table
Словарь, реализованный на AA-дереве.
АA-дерево — структура данных, представляющая собой сбалансированное двоичное дерево поиска, которое является разновидностью красно-черного дерева с дополнительными ограничениями.
* Структуры:
```cpp
struct node {
    size_t level; // уровень
    Node *right; // указатель на правого потомка
    Node *left; // указатель на левого потомка
    Node *parent; //указатель на родителя
    TypeKey key; // ключ, данные связанные с вершиной
    TypeValue value; // значение
};
```
* Поля:
```cpp
private:
    Node<TypeKey, TypeValue>* root; // указатель на корень дерева
```  
* Методы:
```cpp
private:
    void FreeUpMemory(Node<TypeKey, TypeValue>* root); // очищает память, проходя по всему дереву
    void Skew(Node<TypeKey, TypeValue>*); // балансировка дерева: устранение левого горизонтального ребра
    bool Split(Node<TypeKey, TypeValue>*); // балансировка дерева: устранение двух последовательных правых горизонтальных ребер
    void Balance(Node<TypeKey, TypeValue>*); // балансировка дерева
    bool InsertHelp(Node<TypeKey, TypeValue>*, Node<TypeKey, TypeValue>*); // Вспомогающий метод, для вставки элемента. Возращает true, если удалось вставить элемент
    TypeValue* SearchHelp(Node<TypeKey, TypeValue>*, TypeKey, bool change = false, TypeValue* newValue = nullptr); // Вспомогающий метод для поиска элемента. Выбрасывает ошибку, если ключ не найден.
    bool DeleteHelp(Node<TypeKey, TypeValue>*, Node<TypeKey, TypeValue>*, TypeKey); // Вспомогающий метод для удаления элемента.  Возращает true, если удалось удалить элемент

public:
    Table(); // конструктор по умолчанию
    Table(std::pair<TypeKey, TypeValue>* elements); // конструктор
    ~Table(); // деструктор

    bool TryInsert(TypeKey key, TypeValue value) noexcept; // Добавляет новый элемент. Возращает true, если удалось вставить элемент
    bool TryRemove(TypeKey key) noexcept; // Удаляет элемент. Возращает true, если удалось вставить элемент
    bool TryChangeValue(TypeKey key, TypeValue value) noexcept; // Изменяет значение элемента по ключу. Возращает true, если удалось изменить элемент

    std::pair<const TypeValue&, bool> Find(TypeKey key); // Ищет элемент по ключу. Возращает пару: если элемент найден, то возращает значение элемента и true, иначе - дефолтное значение и false

    Table<TypeKey, TypeValue>& operator=(const Table<TypeKey, TypeValue> other); //

    std::pair<TypeValue&, bool> operator[](TypeKey key); // аналог метода Find
    
```  

### 3.ExpressionValidator
* Поля:
```cpp
private:
    Table<std::string, int> operations; // словарь с операциями и их приоритетами
``` 
* Методы:
```cpp
public:
    ExpressionValidator(); // конструктор по умолчанию. Задаёт основные операции. 
    ExpressionValidator(Table<std::string, int>& operations); // конструктор
    bool IsExpressionCorrect(const std::string& expression); // проверяет выражение на корректность
``` 
### 4.ExpressionSeparator
* Перечисления:
```cpp
enum TokenType
{
	Number,
	Letters,
	Operation,
	Default,
};

* Структуры:
```cpp
struct Token {
    TokenType type;
    std::string literal;
    Token(TokenType type = Default, std::string literal = "")
    {
        this->type = type;
        this->literal = literal;
    }
};
```
* Поля:
```cpp
private:
    Table<std::string, int> operations; // словарь с операциями и их приоритетами
``` 
* Методы:
```cpp
private:
    ExpressionSeparator(); // конструктор по умолчанию
    ExpressionSeparator(Table<std::string, int>& operations); // конструктор

    std::vector<Token> GetTokens(const std::string& expression); // разбивает выражения на токены
```

### 4.PostfixExpessions
Поддерживает следующий операции: sin, cos, sqrt, +, унарный +, -, унарный -, *, /, ^ (возведение в степень).
* Поля:
```cpp
private:
    Table<std::string, int> operations; // словарь с операциями и их приоритетами 
    ExpressionValidator expressionValidator;
    ExpressionSeparator expressionSeparator;
``` 
* Методы:
```cpp
private:
    double TryGetResultUnaryFunction(std::string operation, double argument); // возвращает значение унарной функции. Выбрасывает исключение, если операция не может быть выполнена для входного аргумента
    double TryGetResultBinaryFunction(std::string operation, double firstArgument, double secondArgument); // возвращает значение бинарной функции. Выбрасывает исключение, если операция не может быть выполнена для входных аргументов
    double TryGetValue(Token token, Table<std::string, double>* valueLetters); // возвращает значение переменной. Выбрасывает исключение, если значение не найдено

public:
    PostfixExpessions(); // конструктор по умолчанию
    PostfixExpessions(Table<std::string, int>& operations); // конструктор
    std::string TryConvertExpessions(const std::string& expression); // конвертирует выражение в постфиксную форму. Выбрасывает исключение, если выражение некорректно 

    double TryGetResult(const std::string& postExpression, Table<std::string, double>* valueLetters = nullptr); // считает значение выражения в постфиксной форме. Выбрасывает ошибку, если невозможно выполнить какую-либо из операций
```