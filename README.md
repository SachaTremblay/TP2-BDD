###  Basic database project

Pour cloner le project:
`git clone --recursive https://github.com/chemin.vers.repos.git`

Si jamais vous ne voyez pas zig.exe dans Tools, FoundryTools_windowsx64, faite:
`.\setup.bat`

Pour compiler le project:
`ctrl+shift+b`

Pour debugger le project:
`F5`

```mermaid
erDiagram
    
    Client ||--o{ Character : Has
    Client ||--o{ CreditCard : Has
    Client ||--o{ Wallet : Has
    WalletItems ||--o{ Wallet : Has
    WalletItems ||--o{ Items : Has

    Client {
        int ClientID PK
        int CharacterID FK
        int WalletID FK
        int CreditCardID FK
        text Name
        text PassWord
    }
    Character{
        int CharacterID PK
        varchar(16) Name
        int Level
        int Strenght
        int Stealth
        int Stamina
        int Charisma
        int RaceID
        int SocialStatusID
        int FactionID
    }
    CreditCard{
        int CreditCardID PK
        varchar(17) CardNumber
        varchar(32) NameOfCardHolder
        varchar(3) CardCVC
    }
    Wallet{
        int WalletID PK
        int Capacity
        int GGBucksPossessed
    }
    WalletItems{
        int WalltedID FK
        int ItemID FK
    }
    Items{
        int ItemID PK
        varchar(16) ItemName
        int ItemValue
        int IsWeapon
        int Isarmor
        int IsEquipped
        int IsHeavy
        enum Color
    }
```