# Username: sidbelbase
# Aim: To help connect to mongodb database using pymongo including CRUD operations (commented)
# Date: 2022 October 4th

import pymongo
from pymongo import MongoClient

client = pymongo.MongoClient("mongodb+srv://sidbelbase:password@clusters.mongodb.net/test?retryWrites=true&w=majority")
db = client.test
collection = db.test

post = {
	"_id": 1,
	"name": "sid",
	"user_type": "admin",
	"post_count": 18
}

post_two = {
	"_id": 2,
	"name": "paul",
	"user_type": "admin",
	"post_count": 90
}

post_three = {
	"_id": 3,
	"name": "jack",
	"user_type": "admin",
	"post_count": 8000
}

# INSERT

# to insert just one
# collection.insert_one(post)

# for array insertion
# collection.insert_many([post_two, post_three])


# FIND

# for array find
# results = collection.find({"name": "vivek"})
# for res in results:
# 	print(res)

# for indivdual find
# results = collection.find_one({"name": "vivek"})
# print(results)

# for whole find: matches dict which matches the criteria
# result = collection.find_one({})
# results = collection.find({})
# print(results)


# DELETE

# to delete only one
# collection.delete_one({'name':'vivek'})

# to delete many
# collection.delete_many({})


# UPDATE

# to update just one
# result = collection.update_one({"name":"kvivek"}, {"$set": {"name": "vivek", "post_count": 8848}})
# print(result)


# COUNT

# to count documents
# post_counts = collection.count_documents({})
# print(post_counts)
