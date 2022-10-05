---
title: FLUTTER 
description: Flutter Cheat Sheet gives you a quick reference of basic widgets used, snippets and attributes which is very handy while coding. 
created: 2022-10-05
updated: 2022-10-05
---

## Sample program

```html
<!-- Sample program -->
import 'package:flutter/material.dart';

void main() {
    runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Hello world!',
      home: Scaffold(
        body: Center(
          child: Text('Hello world'),
        ),
      ),
    );
  }
}

```

* **`import function** : imports the assets of the specified library from the pubspec.yaml file.
* **`void main()`** : main function that runs first when the app is compiled every time.
* **`class MyApp extends StatelessWidget {}`** : Contains a class (similar to java class) and creates a stateless widget.
* **`  @override`** : @override marks an instance member as overriding a superclass member with the same name.
* **`build(BuildContext context)`** : BuildContext is a locator that is used to track each widget in a tree and locate them and their position in the tree. The BuildContext of each widget is passed to their build method.
* **`Scaffold()`** : Scaffold is a class in flutter which provides many widgets or we can say APIs like Drawer, SnackBar, BottomNavigationBar etc.
* **`body:`** : represents the body of the app , wrapped inside a scaffold , where several widgets can be used to layout a UI.
* **`Center()`** : is a property to wrap around any widget and push the widget layout to be at the center of the screen/widget.
* **`child:`** : It is a property of the parent widget that allows widgets to be put inside widgets , forming a widget tree. 
* **`Text()`** : It's a widget to pass in text to display it on the current screen.

## Stateless Widget

```html
import 'package:flutter/material.dart';

class Greeter extends StatelessWidget {
  Greeter({Key key @required this.name}) : super(key: key);

  final String name;

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Text('Hello, $name'),
    );
  }
}
```

## Stateful Widget

```html
import 'package:flutter/material.dart';

class WidgetWithState extends StatefulWidget {
  @override
  _WidgetWithStateState createState() => _WidgetWithStateState();
}

class _WidgetWithStateState extends State<WidgetWithState> {
  int counter = 0;

  increment() {
    setState(() {
      counter++;
    });
  }

  decrement() {
    setState(() {
      counter--;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Row(
      children: <Widget>[
        FlatButton(onPressed: increment, child: Text('Increment')),
        FlatButton(onPressed: decrement, child: Text('Decrement')),
        Text(counter.toString()),
      ],
    );
  }
}
```

## Required and default props

```html
import 'package:flutter/material.dart';

class SomeComponent extends StatelessWidget {
  SomeComponent({
    @required this.foo,
    this.bar = 'some string',
  });

  final String foo;
  final String bar;

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Text('$foo $bar'),
    );
  }
}
```

## Android Ink effect

```html
InkWell(
  child: Text('Button'),
  onTap: _onTap,
  onLongPress: _onLongPress,
  onDoubleTap: _onDoubleTap,
  onTapCancel: _onTapCancel,
);
```

## Detecting Gestures

```html
GestureDetector(
  onTap: _onTap,
  onLongPress: _onLongPress,
  child: Text('Button'),
);
```

## Loading indicator

```html
class SomeWidget extends StatefulWidget {
  @override
  _SomeWidgetState createState() => _SomeWidgetState();
}

class _SomeWidgetState extends State<SomeWidget> {
  Future future;

  @override
  void initState() {
    future = Future.delayed(Duration(seconds: 1));
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
      future: future,
      builder: (context, snapshot) {
        return snapshot.connectionState == ConnectionState.done
            ? Text('Loaded')
            : CircularProgressIndicator();
      },
    );
  }
}
```

## Platform specific code

```html
import 'dart:io' show Platform;

if (Platform.isIOS) {
  doSmthIOSSpecific();
}

if (Platform.isAndroid) {
  doSmthAndroidSpecific();
}
```

## Hide status bar

```html
import 'package:flutter/services.dart';

void main() {
    SystemChrome.setEnabledSystemUIOverlays([]);
}
```

## Lock orientation

```html
import 'package:flutter/services.dart';

void main() async {
  await SystemChrome.setPreferredOrientations([
    DeviceOrientation.portraitUp,
  ]);

  runApp(App());
}
```

## Make http request

```html
dependencies:
  http: ^0.12.0
```

```html
import 'dart:convert' show json;
import 'package:http/http.dart' as http;

http.get(API_URL).then((http.Response res) {
    final data = json.decode(res.body);
    print(data);
});
```

## Async Await

```html
Future<int> doSmthAsync() async {
  final result = await Future.value(42);
  return result;
}

class SomeClass {
  method() async {
    final result = await Future.value(42);
    return result;
  }
}
```

## JSON

```html
import 'dart:convert' show json;

json.decode(someString);
json.encode(encodableObject);
```

## Check if dev

```html
bool isDev = false;
assert(isDev == true);

if (isDev) {
    doSmth();
}
```

## Navigation

```html
import 'package:flutter/material.dart';

class FirstScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Center(
      child: RaisedButton(
        child: Text('Go to SecondScreen'),
        onPressed: () => Navigator.pushNamed(context, '/second'),
      ),
    );
  }
}

class SecondScreen extends StatelessWidget {
  void _pushSecondScreen(context) {
    Navigator.push(context, MaterialPageRoute(builder: (context) => SecondScreen()));
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      children: <Widget>[
        RaisedButton(
          child: Text('Go back!'),
          onPressed: () => Navigator.pop(context),
        ),
        RaisedButton(
          child: Text('Go to SecondScreen... again!'),
          onPressed: () => _pushSecondScreen(context),
        ),
      ],
    );
  }
}

void main() {
  runApp(MaterialApp(
    initialRoute: '/',
    routes: {
      '/': (context) => FirstScreen(),
      '/second': (context) => SecondScreen(),
    },
  ));
}
```

## Show alert

```html
showDialog<void>(
  context: context,
  barrierDismissible: false,
  builder: (BuildContext context) {
    return AlertDialog(
      title: Text('Alert Title'),
      content: Text('My Alert Msg'),
      actions: <Widget>[
        FlatButton(
          child: Text('Ask me later'),
          onPressed: () {
            print('Ask me later pressed');
            Navigator.of(context).pop();
          },
        ),
        FlatButton(
          child: Text('Cancel'),
          onPressed: () {
            print('Cancel pressed');
            Navigator.of(context).pop();
          },
        ),
        FlatButton(
          child: Text('OK'),
          onPressed: () {
            print('OK pressed');
            Navigator.of(context).pop();
          },
        ),
      ],
    );
  },
);
```

## Arrays

```html
final length = items.length;

final newItems = items..addAll(otherItems);

final allEven = items.every((item) => item % 2 == 0);

final filled = List<int>.filled(3, 42);

final even = items.where((n) => n % 2 == 0).toList();

final found = items.firstWhere((item) => item.id == 42);

final index = items.indexWhere((item) => item.id == 42);

final flat = items.expand((_) => _).toList();

final mapped = items.expand((item) => [item + 1]).toList();

items.forEach((item) => print(item));

items.asMap().forEach((index, item) => print('$item, $index'));

final includes = items.contains(42);

final indexOf = items.indexOf(42);

final joined = items.join(',');

final newItems = items.map((item) => item + 1).toList();

final item = items.removeLast();

items.add(42);

final reduced = items.fold({}, (acc, item) {
  acc[item.id] = item;
  return acc;
});

final reversed = items.reversed;

items.removeAt(0);

final slice = items.sublist(15, 42);

final hasOdd = items.any((item) => item % 2 == 0);

items.sort((a, b) => a - b);

items.replaceRange(15, 42, [1, 2, 3]);

items.insert(0, 42);
```
