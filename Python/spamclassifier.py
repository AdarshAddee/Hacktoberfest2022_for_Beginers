#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd


# In[2]:


messages=pd.read_csv(r"C:\Users\Shovini\Downloads\smsspamcollection\SMSSpamCollection",sep='\t',names=['labels','message'])


# In[3]:


messages


# In[4]:


#data cleaning
import nltk
import re


# In[5]:


from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer
from nltk.stem import WordNetLemmatizer
stemmer=PorterStemmer()
lemmatizer=WordNetLemmatizer()


# In[6]:


#stemming
corpus=[]
for i in range (len(messages)):
    review=re.sub('[^a-zA-Z]',' ',messages['message'][i])
    review=review.lower()
    words=review.split()
    words=[stemmer.stem(word) for word in words if word not in set(stopwords.words("English"))]
    review=" ".join(words)
    corpus.append(review)


# #lemmatization
# corpus=[]
# for i in range (len(messages)):
#     review=re.sub('[^a-zA-Z]',' ',messages['message'][i])
#     review=review.lower()
#     words=review.split()
#     words=[lemmatizer.lemmatize(word) for word in words if word not in set(stopwords.words("English"))]
#     review=" ".join(words)
#     corpus.append(review)

# In[7]:


corpus


# In[8]:


#creating bag of words model
from sklearn.feature_extraction.text import CountVectorizer
cv=CountVectorizer(max_features=2500)#max_features lets you take n most frequent words and binary=true will make it binary bag of words
x=cv.fit_transform(corpus).toarray()


# In[9]:


x


# In[10]:


#get dependent variables
y=pd.get_dummies(messages['labels'])


# In[11]:


y


# In[12]:


y=y.iloc[:,1].values


# In[13]:


y


# In[14]:


# train test split
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.20,random_state=0)
#The random state hyperparameter in the train_test_split() function controls the shuffling process. With random_state=None , we get different train and test sets across different executions and the shuffling process is out of control. With random_state=0 , we get the same train and test sets across different executions.


# In[15]:


#training using Naive Bayes Classifier
from sklearn.naive_bayes import MultinomialNB
spam_detect_model=MultinomialNB().fit(x_train,y_train)
y_pred=spam_detect_model.predict(x_test)


# In[16]:


y


# In[17]:


y_pred


# In[18]:


y_test


# In[19]:


y_pred==y_test


# In[20]:


from sklearn.metrics import confusion_matrix
matrix=confusion_matrix(y_test,y_pred)


# In[21]:


matrix


# In[22]:


from sklearn.metrics import accuracy_score
accuracy=accuracy_score(y_test,y_pred)


# In[23]:


accuracy


# In[ ]:




