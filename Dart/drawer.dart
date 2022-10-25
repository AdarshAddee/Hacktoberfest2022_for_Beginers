import 'package:demo_login/popUpScreen/SuccessAlert.dart';
import 'package:demo_login/utils/appcolor.dart';
import 'package:demo_login/utils/style/style.dart';
import 'package:flutter/material.dart';
import 'package:pinput/pin_put/pin_put.dart';

class ForgetPasswordPage extends StatefulWidget {
  const ForgetPasswordPage({Key? key}) : super(key: key);

  @override
  _ForgetPasswordPageState createState() => _ForgetPasswordPageState();
}

class _ForgetPasswordPageState extends State<ForgetPasswordPage> {
  final TextEditingController _fogetPaaswordController =
      TextEditingController();
  final FocusNode _forgetPasswordFocusNode = FocusNode();

  Map data = {};

  BoxDecoration get _pinPutDecoration {
    return BoxDecoration(
      border: Border.all(color: primarytheme),
      borderRadius: BorderRadius.circular(20.0),
    );
  }

  @override
  Widget build(BuildContext context) {
    data = data.isNotEmpty
        ? data
        : ModalRoute.of(context)!.settings.arguments as Map;
    // print(data['email']);
    return Scaffold(
      body: Center(
        child: SingleChildScrollView(
          child: Padding(
            padding: const EdgeInsets.all(8.0),
            child: Column(
              children: <Widget>[
                Container(
                  height: MediaQuery.of(context).size.height / 4, //4.5
                  width: MediaQuery.of(context).size.width, //2.5
                  decoration: const BoxDecoration(
                    image: DecorationImage(
                        image:
                            AssetImage('assets/images/Forgot_password_re_.png'),
                        alignment: Alignment.topCenter),
                  ),
                ),
                const SizedBox(
                  height: 50,
                ),
                Container(
                    alignment: Alignment.center,
                    child: const Text("Enter OTP Sent To Your Email ",
                        style: TextStyle(
                            fontWeight: FontWeight.bold,
                            fontSize: 20,
                            color: primarytheme))),
                Container(
                  margin: const EdgeInsets.all(20.0),
                  padding: const EdgeInsets.all(20.0),
                  //otp function
                  child: PinPut(
                    //number of otp pin
                    fieldsCount: 5,
                    onSubmit: (String pin) => onSucessAlert(context, data),
                    focusNode: _forgetPasswordFocusNode,
                    controller: _fogetPaaswordController,
                    submittedFieldDecoration: _pinPutDecoration.copyWith(
                      borderRadius: BorderRadius.circular(20.0),
                    ),
                    selectedFieldDecoration: _pinPutDecoration,
                    followingFieldDecoration: _pinPutDecoration.copyWith(
                      borderRadius: BorderRadius.circular(15.0),
                      border: Border.all(
                        color: primarytheme.withOpacity(1),
                      ),
                    ),
                  ),
                ),
                SizedBox(
                  child: GestureDetector(
                    onTap: () {
                      //request for another password
                      // ignore: avoid_print
                      print("resent otp");
                    },
                    child: const Text(
                      'Resend OTP?',
                      style: textStyleText,
                      textAlign: TextAlign.right,
                    ),
                  ),
                ),
                const SizedBox(height: 100),
                SizedBox(
                  height: 40,
                  width: 150,
                  child: GestureDetector(
                    onTap: () => _fogetPaaswordController.text = '',
                    child: buttonWidgetPrimary('Clear All'),
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}



class NewPassword extends StatefulWidget {
  const NewPassword({Key? key}) : super(key: key);

  @override
  _NewPasswordState createState() => _NewPasswordState();
}

class _NewPasswordState extends State<NewPassword> {
  Map data = {};
  final _formKey = GlobalKey<FormState>();

  String password = '';

  moveToLogin(BuildContext context) async {
    if (_formKey.currentState!.validate()) {
      await onSucessPassword(context);
    }
  }

  @override
  Widget build(BuildContext context) {
    data = data.isNotEmpty
        ? data
        : ModalRoute.of(context)!.settings.arguments as Map;
    // print('new Password '+data.toString());
    return Material(
      child: SingleChildScrollView(
        child: Form(
            key: _formKey,
            child: Column(
              children: [
                SizedBox(
                  height: MediaQuery.of(context).size.height / 4, //4.5
                  width: MediaQuery.of(context).size.width / 2,
                  child: Image.asset(
                    "assets/images/protection_Monochromatic.png",
                    fit: BoxFit.cover,
                  ),
                ),
                const SizedBox(
                  height: 85.0,
                ),
                Padding(
                  padding: const EdgeInsets.symmetric(
                      vertical: 16.0, horizontal: 32.0),
                  child: Column(
                    children: [
                      SizedBox(
                          height: 50,
                          width: 1000,
                          child:
                              // displaying email id
                              Text(
                            "Email : " + data['email'],
                            textAlign: TextAlign.left,
                            style: textStyleTheme,
                            //textScaleFactor: 2.0,
                          )),
                      TextFormField(
                        obscureText: true,
                        decoration: const InputDecoration(
                          border: underlineInputBorder,
                          focusedBorder: underlineInputBorder,
                          labelStyle: textboxTextStyle,
                          hintText: "Enter New password",
                          labelText: "New Password",
                        ),

                        onChanged: (value) => password = value,
                        // assign the the multi validator to the TextFormField validator
                        // validator: passwordValidator,
                        validator: (password) {
                          if (password!.isEmpty) {
                            return 'Password required';
                          } else if (password.length < 8) {
                            return 'password must be at least 8 digits long';
                          } else if (!(RegExp(r"(?=.*?[#?!@$%^&*-])")
                              .hasMatch(password))) {
                            return 'passwords must have at least one special character';
                          }
                          return null;
                        },
                      ),
                      const SizedBox(
                        height: 30,
                      ),
                      TextFormField(
                          obscureText: true,
                          decoration: const InputDecoration(
                            labelStyle: textboxTextStyle,
                            border: underlineInputBorder,
                            focusedBorder: underlineInputBorder,
                            labelText: "Confirm  Password",
                            hintText: "Confirm password",
                          ),
                          validator: (value) {
                            if (value!.isEmpty) {
                              return "confirm Password ";
                            } else if (password != value) {
                              return 'Password do not match';
                            }
                            return null;
                          }),
                      const SizedBox(
                        height: 60.0,
                      ),
                      SizedBox(
                        height: 50,
                        width: 100,
                        child: GestureDetector(
                          onTap: () => moveToLogin(context),
                          child: buttonWidgetPrimary('SUBMIT'),
                        ),
                      ),
                    ],
                  ),
                )
              ],
            )),
      ),
    );
  }
}


