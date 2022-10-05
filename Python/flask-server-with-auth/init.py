from server_pkg.app import create_app,db
from flask_migrate import upgrade,migrate,init,stamp
from server_pkg.models import User
from server_pkg.app import bcrypt
import os

def deploy():
	"""Run deployment tasks."""
	app = create_app()
	app.app_context().push()
	db.create_all()

	# migrate database to latest revision
	init()
	stamp()
	migrate()
	upgrade()
	
deploy()
	


def init_admin():
	email = input("Enter email for admin\t: ")
	pwd = input("Enter password for admin\t: ")
	username = "admin"

	Admin = User(
		username=username,
		email=email,
		pwd=bcrypt.generate_password_hash(pwd)
	)

	db.session.add(Admin)
	db.session.commit()

init_admin()
