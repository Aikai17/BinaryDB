# BinaryDB — простая in-memory база данных с бинарным протоколом

Этот проект — минималистичная высокопроизводительная in-memory база данных, вдохновлённая Redis, с бинарным протоколом на основе Protocol Buffers.

## 📦 Возможности

- `SET key value` — сохранить значение
- `GET key` — получить значение
- Сетевой сервер на `Boost.Asio`
- Сериализация/десериализация через Protocol Buffers
- Thread-safe in-memory хранилище (`std::shared_mutex`)
- Многопоточность (`std::thread`)
- Быстрая двоичная передача данных между клиентом и сервером

---

## 📁 Структура проекта

```
.
├── CMakeLists.txt
├── main.cpp
├── server.hpp / server.cpp
├── storage.hpp / storage.cpp
├── proto/
│   ├── db.proto
│   ├── db.pb.h      ← уже сгенерировано заранее
│   └── db.pb.cc     ← уже сгенерировано заранее
└── README.md
```

---

## ⚙️ Зависимости

- **CMake** ≥ 3.16
- **C++20**
- **Boost** (`system`, `thread`)
- **Protobuf** (v22+)
- **Abseil** (используется внутри Protobuf)

---

## 🔧 Сборка проекта

```bash
git clone https://github.com/yourname/BinaryDB.git
cd BinaryDB

mkdir build && cd build
cmake ..
make
```
---

## 🚀 Запуск

### Сервер

```bash
./BinaryDB
```

Сервер будет слушать порт `12345`.

---

## 🧪 Использование
Просмотрите репозиторий с клиентом: 




