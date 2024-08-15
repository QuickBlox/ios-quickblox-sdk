<div align="center">

<p>
		<a href="https://discord.gg/c6bxq9BC"><img src="https://img.shields.io/discord/1042743094833065985?color=5865F2&logo=discord&logoColor=white&label=QuickBlox%20Discord%20server&style=for-the-badge" alt="Discord server" /></a>
</p>

</div>

# Quickblox IOS SDK

QuickBlox iOS SDK ([Quickblox Framework](https://github.com/QuickBlox/ios-quickblox-sdk/tree/master/Quickblox.xcframework))

Last SDK Version: 2.20.0

The [QuickBlox](https://quickblox.com) platform provides the QuickBlox iOS SDK is a software development kit that provides a set of tools and APIs to help iOS developers build communication features into their apps.
The QuickBlox iOS SDK is designed to work with Objective-C and Swift languages and provides various features such as messaging, video calling, push notifications, and user authentication.

# Install

QuickBlox iOS SDK is available using the [Swift Package Manager](https://www.swift.org/package-manager/) (SPM) as of version 2.19.0.

To add QuickBlox IOS SDK to your project using SPM, you can follow these steps:

1. Open your Xcode project and navigate to File > Swift Packages > Add Package Dependency.
2. In the search bar, enter the QuickBlox repository URL: https://github.com/QuickBlox/ios-quickblox-sdk.git  and click Add Package.
3. Xcode will then fetch the QuickBlox iOS SDK and you can add it to your project by clicking Add Package.
4. You can then import QuickBlox modules into your code and use its API.

For more information on spm customization options, you can refer to the [Apple Documentation](https://developer.apple.com/documentation/xcode/adding-package-dependencies-to-your-app).

# Features

The QuickBlox iOS SDK includes several modules that provide different functionalities such as:

- [Chat module](https://docs.quickblox.com/docs/ios-chat): Provides APIs to implement one-to-one and group chat functionalities in your app. 
- [Video chat module](https://docs.quickblox.com/docs/ios-video-calling): Provides APIs for video calling and conferencing features in your app.
- [Users module](https://docs.quickblox.com/docs/ios-users): Provides APIs for user management and authentication in your app.
- [Push notifications module](https://docs.quickblox.com/docs/ios-push-notifications): Provides APIs for integrating push notifications into your app.

For detailed information, including step-by-step guides to get started quickly, please refer to the official [QuickBlox iOS SDK Quick Start Guide](https://docs.quickblox.com/docs/ios-quick-start).

QuickBlox offers both a free and a paid plan with different [pricing](https://quickblox.com/pricing/) models, so you can choose the one that fits your needs.

# AI Features

AI Features base on SmartChat Assistants

## Overview

Starting from version 2.20.0 of QuickBlox iOS SDK, the AI functionality is enabled and based on our SmartChat Assistants. The QuickBlox iOS SDK provides a range of features to enhance the chat experience. With essential messaging functionalities such as answer assistant, users can engage in more interactive conversations.

**Supported features**

| Name         | Description                                                              |
| :----------- | :----------------------------------------------------------------------- |
| AI Assist    | Provides answers based on chat history to selected message.              |
| AI Translate | Provides translation based on chat history to selected incoming message. |

## Requirements

The minimum requirements for using AI features are:

- QuickBlox iOS SDK v2.20.0
- Quickblox account with activated SmartChat Assistants

Visit our [Key Concepts](doc:key-concepts) page to get an overall understanding of the most important QuickBlox concepts.

Visit our [Smart Chat Assistant overview](https://docs.quickblox.com/docs/smartchat-assistant-overview) page to get an overall understanding of the most important SmartChat Assistants concepts.

## Before you begin

1. Register a [QuickBlox account](https://admin.quickblox.com/signin). This is a matter of a few minutes and you will be able to use this account to build your apps.
2. Configure QuickBlox SDK for your app. Check out our [Setup](https://docs.quickblox.com/docs/ios-setup) page for more details. 
3. Create a user session to be able to use QuickBlox functionality. See our [Authentication](https://docs.quickblox.com/docs/ios-authentication) page to learn how to do it.
4. Create or update your SmartChat Assistant. See our [Smart Chat Assistant](https://docs.quickblox.com/docs/smartchat-assistant-overview#create-smartchat-assistant) documentation to learn how to do it.

### Review your SmartChat Assistant

To get **ID **of SmartChat Assistant to use it as `smartChatAssistantId ` param follow the steps below:

1. Navigate to the **Dashboard => _YOUR_APP_ => SmartChat Assistant** page.
2. Choose the ID of the SmartChat Assistant you want to update and click on it.
3. Edit the SmartChat Assistant settings.
4. Click the Save button to save changes.

<img src="/assets/images/SmartChatAssistant.png"/>


## AI Assist Answer

QuickBlox provides answer assistant functionality that helps users effortlessly send various answers considering chat history.

### How to use Assist Answer

```swift
let smartChatAssistantId = "XXXXXXXXXXXXXXXXXXXXXXXX"
let messageToAssist = "What is Quickblox?"

let history = [QBAnswerAssistHistoryMessage(role: .assistant, message: "History message"),
	       QBAnswerAssistHistoryMessage(role: .user, message: "Hi"),
	       QBAnswerAssistHistoryMessage(role: .assistant, message: "Hello! How can I assist you today?")
]

let result = try await QB.ai.answerAssist(withSmartChatAssistantId: smartChatAssistantId,
					  messageToAssist: messageToAssist,
				          history: history)
let answer = result.answer
// handle answer
```
```objectivec
NSString *smartChatAssistantId = @"XXXXXXXXXXXXXXXXXXXXXXXX";
NSString *messageToAssist = @"What is Quickblox?";
    
NSArray *history = @[
    [[QBAnswerAssistHistoryMessage alloc] initWithRole:QBAIRoleTypeAssistant message:@"History message"],
    [[QBAnswerAssistHistoryMessage alloc] initWithRole:QBAIRoleTypeUser message:@"Hi"],
    [[QBAnswerAssistHistoryMessage alloc] initWithRole:QBAIRoleTypeAssistant message:@"Hello! How can I assist you today?"]
];
    
[QB.ai answerAssistWithSmartChatAssistantId:smartChatAssistantId
			    messageToAssist:messageToAssist
		                    history:history
			         completion:^(id<QBAIAnswerAssistResultProtocol>  _Nonnull result, NSError * _Nullable error) {
    if (result) {
        NSString *answer = result.answer;
        // handle answer
    }
}];
```

| Parameter name       | Type            | Description                                                                                                                                                                                                                                          |
| :------------------- | :-------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| smartChatAssistantId | String          | This field should hold your actual Smart Chat Assistant ID that you'll receive from the Quickblox account. This ID is used to authenticate your requests to the AI service.                                                                          |
| messageToAssist      | String          | Message you want to get answer for.                                                                                                                                                                                                                  |
| history              | Array of Object | Conversation history. Used to add context. Each object of array should have the two fields: 'role' and 'message'. The field role should contains one of next values: 'user' or 'assistant'.  The field message should be a string with chat message. |

## AI Translate

QuickBlox offers translation functionality that helps users easily translate text messages in chat, taking into account the context of the chat history.

### How to use AI Translate

```swift
let smartChatAssistantId = "XXXXXXXXXXXXXXXXXXXXXXXX"
let textToTranslate = "Hola!"
let languageCode = "en"
        
let result = try await QB.ai.translate(withSmartChatAssistantId: smartChatAssistantId,
				       textToTranslate: textToTranslate,
				       languageCode: languageCode)
let answer = result.answer
// handle answer
```
```objectivec
NSString *smartChatAssistantId = @"XXXXXXXXXXXXXXXXXXXXXXXX";
NSString *textToTranslate = @"Hola!";
NSString *languageCode = @"en";
    
[QB.ai translateWithSmartChatAssistantId:smartChatAssistantId
  			 textToTranslate:textToTranslate
			    languageCode:languageCode
			      completion:^(id<QBAITranslateResultProtocol>  _Nonnull result, NSError * _Nullable error) {
    if (result) {
        NSString *answer = result.answer;
        // handle answer
    }
}];    
```

| Parameter name       | Type    | Description                                                                                                                                                                 |
| :------------------- | :------ | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| smartChatAssistantId | String  | This field should hold your actual Smart Chat Assistant ID that you'll receive from the Quickblox account. This ID is used to authenticate your requests to the AI service. |
| textToTranslate      | String  | Text to translate.                                                                                                                                                          |
| languageCode         | Stringt | Translation language code.                                                                                                                                                  |

# Requirements

The Swift Package Manager requires Xcode 11 or later and is only available for macOS and iOS projects.
* XCode 12+
* iOS 13+
