import json
from Classifier import KNearestNeighbours
from operator import itemgetter
import hashlib
from PIL import Image
import plotly.express as px
import pandas as pd
import sqlite3
import requests
import streamlit as st
import base64

conn = sqlite3.connect('data1.db', check_same_thread=False)
c = conn.cursor()

#DB management for searchlist
def create_table():
    c.execute('CREATE TABLE IF NOT EXISTS taskstable(task TEXT)')


def add_data(task):
    c.execute('INSERT INTO taskstable(task) VALUES (?)', [task])
    conn.commit()


def view_all_data():
    c.execute('SELECT * FROM taskstable')
    data = c.fetchall()
    return data


def view_all_searchlist():
    c.execute('SELECT DISTINCT task FROM taskstable')
    data = c.fetchall()
    return data


def delete_data(task):
    c.execute('DELETE FROM taskstable WHERE task="{}"'.format(task))
    conn.commit()

    #creating a login based system 

def make_hashes(password):
    return hashlib.sha256(str.encode(password)).hexdigest()


def check_hashes(password, hashed_text):
    if make_hashes(password) == hashed_text:
        return hashed_text
    return False


# DB Management
import sqlite3

conn = sqlite3.connect('data.db')
c = conn.cursor()


# DB Functions
def create_usertable():
    c.execute('CREATE TABLE IF NOT EXISTS userstable(username TEXT,password TEXT)')


def add_userdata(username, password):
    c.execute('INSERT INTO userstable(username,password) VALUES (?,?)', (username, password))
    conn.commit()


def login_user(username, password):
    c.execute('SELECT * FROM userstable WHERE username =? AND password = ?', (username, password))
    data = c.fetchall()
    return data


def view_all_users():
    c.execute('SELECT * FROM userstable')
    data = c.fetchall()
    return data


# Load data and movies list from corresponding JSON files
with open(r'data.json', 'r+', encoding='utf-8') as f:
    data = json.load(f)
with open(r'titles.json', 'r+', encoding='utf-8') as f:
    movie_titles = json.load(f)


def knn(test_point, k):
    # Create dummy target variable for the KNN Classifier
    target = [0 for item in movie_titles]
    # Instantiate object for the Classifier
    model = KNearestNeighbours(data, target, test_point, k=k)
    # Run the algorithm
    model.fit()
    # Distances to most distant movie
    max_dist = sorted(model.distances, key=itemgetter(0))[-1]
    # Print list of 10 recommendations < Change value of k for a different number >
    table = list()
    for i in model.indices:
        # Returns movie title and imdb link
        table.append([movie_titles[i][0], movie_titles[i][2]])
    return table


st.set_page_config(layout="wide", page_title="Movie Recommendation System")


@st.cache(allow_output_mutation=True)
def get_base64_of_bin_file(bin_file):
    with open(bin_file, 'rb') as f:
        data = f.read()
    return base64.b64encode(data).decode()


def set_png_as_page_bg(png_file):
    bin_str = get_base64_of_bin_file(png_file)
    page_bg_img = '''
    <style>
    .stApp {
    background-image: url("data:image/png;base64,%s");
    background-size: cover;
    }
    </style>   
    ''' % bin_str
    st.markdown(page_bg_img, unsafe_allow_html=True)
    return
set_png_as_page_bg('we5.png')
def local_css(file_name):
    with open(file_name) as f:
        st.markdown(f"<style>{f.read()}</style>", unsafe_allow_html=True)

st.markdown(
    """
    <style>
    .sidebar .sidebar-content {
    color: Black;
    }
    </style>
    """,
    unsafe_allow_html=True,)

# class AgGrid:
# pass


class AgGrid:
    pass


class AgGrid:
    pass

#main function (its easy to understand)
# e4d96f
if __name__ == '__main__':
    img1 = Image.open('heading.png')
    img1 = img1.resize((1050, 300), )
    st.image(img1, use_column_width=False)

    menu = ["Home", "Login", "SignUp", "About", "Contribute", "Feedback form"]
    choice = st.sidebar.selectbox("Menu", menu)
    if choice == "Home":
        col1, col2, col3 = st.columns([1, 1, 1])

        with col2:
            file_ = open("hel.gif", "rb")
            contents = file_.read()
            data_url = base64.b64encode(contents).decode("utf-8")
            file_.close()
            st.markdown(
                f'<img src="data:image/gif;base64,{data_url}" alt="cat gif">',
                unsafe_allow_html=True,
            )

        st.markdown(""" <style> .font {
                                                 font-size:30px ; font-family: 'Trebuchet MS'; color:	#C0C0C0; text-align:center;} 
                                               </style> """, unsafe_allow_html=True)
        st.markdown('<p class="font">Hey movie geek, We hope you got your popcorns ready!</p>',
                    unsafe_allow_html=True)

        st.write('<br>', unsafe_allow_html=True)
        img1 = Image.open('we3.webp')
        img1 = img1.resize((1000, 600), )
        st.image(img1, use_column_width=False)
        st.write('<br>', unsafe_allow_html=True)
        
        ch = st.checkbox('I Agree With Terms And Conditions')
        if ch:
            st.write('Thank you For Agreeing')
            
    elif choice == "Login":
        col1, col2, col3 = st.columns([1, 2, 1])
        with col2:
            file_ = open("hello.gif", "rb")
            contents = file_.read()
            data_url = base64.b64encode(contents).decode("utf-8")
            file_.close()
            st.markdown(
                f'<img src="data:image/gif;base64,{data_url}" alt="cat gif">',
                unsafe_allow_html=True,
            )
        st.sidebar.write('Do press enter after putting your username and password to apply')
        username = st.sidebar.text_input("User Name ")
        password = st.sidebar.text_input("Password", type='password')
        
        we = st.sidebar.checkbox("Login")
        if we:
            # if password == '12345':
            create_usertable()
            hashed_pswd = make_hashes(password)
            result = login_user(username, check_hashes(password, hashed_pswd))
            if result:
                st.success("Hey {} !".format(username))
                img1 = Image.open('we.png')
                img1 = img1.resize((800, 500), )
                st.image(img1, use_column_width=False)

                genres = ['Action', 'Adventure', 'Animation', 'Biography', 'Comedy', 'Crime', 'Documentary', 'Drama',
                          'Family',
                          'Fantasy', 'Film-Noir', 'Game-Show', 'History', 'Horror', 'Music', 'Musical', 'Mystery',
                          'News',
                          'Reality-TV', 'Romance', 'Sci-Fi', 'Short', 'Sport', 'Thriller', 'War', 'Western']

                movies = [title[0] for title in movie_titles]
                st.header('Movie Recommendation System')
                apps = ['--Select--', 'Movie based', 'Genres based']
                app_options = st.selectbox('Select application:', apps)

                if app_options == 'Movie based':
                    movie_select = st.selectbox('Select movie:', ['--Select--'] + movies)
                    if movie_select == '--Select--':
                        st.write('Select a movie')
                    else:
                        n = st.number_input('Number of movies:', min_value=5, max_value=20, step=1)
                        genres = data[movies.index(movie_select)]
                        test_point = genres
                        table = knn(test_point, n)
                        for movie, link in table:
                            # Displays movie title with link to imdb
                            st.markdown(f"[{movie}]({link})")
                elif app_options == apps[2]:
                    options = st.multiselect('Select genres:', genres)
                    if options:
                        imdb_score = st.slider('IMDb score:', 1, 10, 8)
                        n = st.number_input('Number of movies:', min_value=5, max_value=20, step=1)
                        test_point = [1 if genre in options else 0 for genre in genres]
                        test_point.append(imdb_score)
                        table = knn(test_point, n)
                        for movie, link in table:
                            # Displays movie title with link to imdb
                            st.markdown(f"[{movie}]({link})")

                    else:
                        st.write("This is a simple Movie Recommender application. "
                                 "You can select the genres and change the IMDb score.")

                else:
                    st.write('Select option')

                new_title = '<br></br>'
                st.markdown(new_title, unsafe_allow_html=True)
                tit = st.text_input('Know The Details Of Your Favorite Movie:')
                new_title1 = tit
                new_title3 = ''
                if tit:
                    try:
                        new_title3 = 'found'
                        url = f"http://www.omdbapi.com/?t={tit}&apikey={'d23bf78a'}"
                        re = requests.get(url)
                        re = re.json()
                        col1, col2 = st.columns([1, 2])
                        with col1:
                            st.image(re['Poster'])
                        with col2:
                            st.subheader(re['Title'])
                            st.caption(f"Genre: {re['Genre']} Year: {re['Year']} ")
                            st.write(re['Plot'])
                            st.text(f"Rating: {re['imdbRating']}")
                            st.progress(float(re['imdbRating']) / 10)

                    except:
                        new_title3 = 'not found'
                        st.error('No Movie Found')

                new_title = '<br></br>'
                st.markdown(new_title, unsafe_allow_html=True)
                menu = ["Read", "Delete"]
                st.markdown(""" <style> .font {
                                          font-size:30px ; font-family: 'Trebuchet MS'; 	color: #FD1C03; text-align:center;} 
                                        </style> """, unsafe_allow_html=True)
                st.markdown('<p class="font">Recent Searches</p>',
                            unsafe_allow_html=True)

                choice1 = st.selectbox("Recent Searches menu", menu)
                create_table()
                if new_title3 == 'found':
                    add_data(new_title1)
                    st.success("Added {} To Recent Searches".format(new_title1))
                elif new_title3 == 'not found':
                    st.error('No movie Found')
                if choice1 == "Read":
                    with st.expander("View All"):
                        result = view_all_data()
                        # st.write(result)
                        clean_df = pd.DataFrame(result, columns=["Recent Searches"])
                        st.dataframe(clean_df)
                elif choice1 == "Delete":
                    st.subheader("Delete")
                    with st.expander("View Data"):
                        result = view_all_data()
                        # st.write(result)
                        clean_df = pd.DataFrame(result, columns=["Recent Searches"])
                        st.dataframe(clean_df)

                    unique_list = [i[0] for i in view_all_searchlist()]
                    delete_by_task_name = st.selectbox("Select Searches", unique_list)
                    if st.button("Delete"):
                        delete_data(delete_by_task_name)
                        st.warning("Deleted: '{}'".format(delete_by_task_name))

                    with st.expander("Updated Data"):
                        result = view_all_data()
                        # st.write(result)
                        clean_df = pd.DataFrame(result, columns=["Recent Searches"])
                        st.dataframe(clean_df)


            else:
                st.warning("Incorrect Username/Password")



    elif choice == "SignUp":
        st.markdown(""" <style> .font {
                                                     font-size:30px ; font-family: 'Trebuchet MS'; color: #FD1C03;  text-align:center;} 
                                                  </style> """, unsafe_allow_html=True)
        st.markdown('<p class="font">Create New Account</p>', unsafe_allow_html=True)
        new_user = st.text_input("Username")
        new_password = st.text_input("Password", type='password')

        if st.button("Signup"):
            create_usertable()
            add_userdata(new_user, make_hashes(new_password))
            st.success("You have successfully created a valid Account")
            st.info("Go to Login Menu to login")
            st.balloons()


    elif choice == "About":

        st.markdown(""" <style> .font {
                  font-size:30px ; font-family: 'Trebuchet MS'; color: #FD1C03; text-align:center;; } 
                  </style> """, unsafe_allow_html=True)
        st.markdown('<p class="font">About Us:</p>', unsafe_allow_html=True)

        col1, col2, col3 = st.columns([1, 1, 1])

        with col1:
            st.write("")

        with col2:
            img1 = Image.open('we4.jpeg')
            img1 = img1.resize((300, 300), )
            st.image(img1, use_column_width=False)

        with col3:
            st.write("")

        new_title = '<p></p>'
        st.markdown(new_title, unsafe_allow_html=True)

        st.markdown(""" <style> .font2 {
                         font-size:20px ; font-family: 'Trebuchet MS'; color:	#C0C0C0; } 
                         </style> """, unsafe_allow_html=True)
        st.markdown(
            '<p class="font2" >This is a movie recommendation engine built as a part of Microsoft engage mentorship programme.It recommends movies to the user based on their input of genre or movie. '
            'It also allows the user to read a short description of movie along with their imdb rating upon searching its name.</p>',
            unsafe_allow_html=True)
        st.markdown(
            '<p class="font2" >It has been developed by Juhi Vishwakarma, a pre-final year student of IIT Roorkee who majors in Mechanical Engineering. Along with movies and ice cream the developer enjoys doing competitive programming, problem solving and a lit bit of development here and there.</p>',
            unsafe_allow_html=True)

    elif choice == "Contribute":
        st.markdown(""" <style> .font {
                    font-size:30px ; font-family: 'Trebuchet MS'; color: #FD1C03;  text-align:center;} 
                  </style> """, unsafe_allow_html=True)
        st.markdown('<p class="font">Wanna Contribute In our Project ? </p>', unsafe_allow_html=True)
        new_title = '<br></br>'
        st.markdown(new_title, unsafe_allow_html=True)

        st.markdown(""" <style> .font21 {
                        font-size:20px ; color: White; text-align:center;} 
                        </style> """, unsafe_allow_html=True)
        st.markdown('<p class="font21">Are we missing a favorite of your movies in our database? Dont Worry  we had '
                    'you covered, send us a list of the missing masterpieces and we will include them in our corpus '
                    '</p>', unsafe_allow_html=True)
        st.subheader("DocumentFiles")
        docx_file = st.file_uploader("Upload Document", type=["txt"])
        if st.button("Process"):
            if docx_file is not None:
                file_details = {"filename": docx_file.name, "filetype": docx_file.type,
                                "filesize": docx_file.size}
                st.write(file_details)
                if docx_file.type == "text/plain":
                    # Read as string (decode bytes to string)
                    raw_text = str(docx_file.read(), "utf-8")
                    st.text(raw_text)
            else:
                st.write('Upload a  file')
        we = st.button('Submit')
        if we:
            st.success("You have successfully Submitted Your File")
    elif choice == "Feedback form":
        st.markdown(""" <style> .font {
               font-size:30px ; font-family: 'Trebuchet MS'; color: #FD1C03;  text-align:center;} 
             </style> """, unsafe_allow_html=True)
        st.markdown('<p class="font">Fill up the feedback form</p>', unsafe_allow_html=True)
        contact_form = """
        <form action="https://formsubmit.co/temporaryytemp@gmail.com" method="POST">
             <input type="hidden" name="_captcha" value="false">
             <input type="text" name="name" placeholder="Your name" required>
             <input type="email" name="email" placeholder="Your email" required>
             <textarea name="message" placeholder="Your message here"></textarea>
             <button type="submit">Send</button>
        </form>
        """
        st.markdown(contact_form, unsafe_allow_html=True)
        local_css("style.css")
