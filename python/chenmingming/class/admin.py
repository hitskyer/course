from user import User
class Privileges:
    def __init__(self):
        self.privileges = ["can add post","can delete post","can ban user"]
    def show_privileges(self):
        for p in self.privileges:
            print(p,'\n')
class Admin(User):
    def __init__(self, first_name, last_name, **other_profile):
        super().__init__(first_name, last_name, **other_profile)
        self.priv = Privileges()

user001 = Admin('chen','mingiming',height=178,weight='70kg')
user001.greet_user()
user001.describe_user()
user001.priv.show_privileges()