# NekoEngine (ECS) - Really early state
 
You can download and try it. Actually it has a demo where a square move in screen.

**Don't use NekoEngine actually**
 
## Entity

Everything can move in game is an **Entity**. Entity can have many **Component** attached and it can access to them in this manner:

```
// Internal Access
GetComponent<MyComponent>();
// External Access
myEntity.GetComponent<MyComponent>();
```

Every Entity has a **Transform** component attached by default.

## Component

To add a functionality to your **Entity** you should create a class inheritating **Component** like this:

```
#include "Component.h"

class CustomComponent : Component
{
public:
    CustomComponent(Entity entity) : Component(entity) { }
}
```

**N.B.**
Default methods like Update() will be implemented soon.

## GameTime

Actually time is handled by GameTime class.

#### Exposed Methods

| Method | Description |
| --- | --- |
| GetInstance() | Retrieve **GameTime** instace to access time datas |
| Uint64 GetTime() | Retrieve elapsed time since game is started in milliseconds |
| double GetDeltaTime() | Retrieve elapsed time (seconds) since last frame and current one |

## GameEvent

It permits to Entitys (and not only) to create GameEvents to which subscribe. They can handle void, mono arg and dual args events.

### Creating event

```
GameEvent<> OnButtonClick = GameEvent<>();
GameEvent<float> OnHealthChange = GameEvent<float>();
GameEvent<string, int> OnPlayerScoreChange = GameEvent<string, int>();
```

### (Un)Subscring to events

```
void MyFunction() 
{
    // Subscribing to event
    player.OnHealthChange.AddSubscriber(std::bind(&MySubscribedFunction));
    // Unsubscribing to event
    player.OnHealthChange.RemoveSubscriber(std::bind(&MySubscribedFunction));
}

void MySubscribedFunction(float currentHealth)
{
    // do stuff
}

```

### Notify events

```
OnButtonClick.Notify();
OnHealthChange.Notify(currentHealth);
OnPlayerScoreChange.Notify(playerName, playerScore);
```

## Input

It handles input, managing Press and Release states.

#### Example
```
Input::GetInstance().OnDownKeyPress.AddSubscriber(std::bind(&DownKeyPress));
```

KeyMapping based (still not ready).

## Transform

Default **Entity** component, it stores world position data.
**More details soon**

## Vector3

Storing 3D vector datas.
**More details soon**

## Color

Storing Color datas.

```
// Creating new color
Color myColor = Color(111, 111, 111, 255);
// Using default color
Color myColor2 = Color::White();
```

#### Default colors:

| Color | Code |
| --- | --- |
| Transparent() | (255, 255, 255, 0) |
| White() | (255, 255, 255) |
| Black() | (0, 0, 0) |
| Red() |  (255, 0, 0) |
| Green() | (0, 255, 0) |
| Blue() | (0, 0, 255) |

## Garbage Collector

**Actually it doesn't exists. It will come soon!**
