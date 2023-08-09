#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/connection.h>
#include <cppconn/exception.h>
#include <wx/wx.h>

class HomePageFrame : public wxFrame
{
public:
    HomePageFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        panel->SetBackgroundColour(wxColour(255, 255, 255)); // Set white background color

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        panel->SetSizer(mainSizer);

        wxStaticText* lbl_welcome = new wxStaticText(panel, wxID_ANY, "Welcome to the Home Page!", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
        lbl_welcome->SetFont(wxFont(wxFontInfo(20).Bold()));

        mainSizer->Add(lbl_welcome, 1, wxALIGN_CENTER | wxALL, 20);

        Center();
    }
};

class LoginFrame : public wxFrame
{
public:
    LoginFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 200))
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        panel->SetBackgroundColour(wxColour(240, 240, 240)); // Set light gray background color

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        panel->SetSizer(mainSizer);

        wxStaticText* lbl_username = new wxStaticText(panel, wxID_ANY, "Username:");
        input_username = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

        wxStaticText* lbl_password = new wxStaticText(panel, wxID_ANY, "Password:");
        input_password = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);

        wxButton* btn_login = new wxButton(panel, wxID_ANY, "Login");
        wxButton* btn_register = new wxButton(panel, wxID_ANY, "Register");

        // Add controls to the sizer with appropriate spacing
        mainSizer->AddSpacer(20);
        mainSizer->Add(lbl_username, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);
        mainSizer->Add(input_username, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 15);
        mainSizer->Add(lbl_password, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);
        mainSizer->Add(input_password, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 15);
        mainSizer->Add(btn_login, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
        mainSizer->Add(btn_register, 0, wxALIGN_CENTER_HORIZONTAL, 5);

        // Set font for labels and buttons
        wxFont labelFont(wxFontInfo(12).Bold());
        wxFont buttonFont(wxFontInfo(10).Bold());
        lbl_username->SetFont(labelFont);
        lbl_password->SetFont(labelFont);
        btn_login->SetFont(buttonFont);
        btn_register->SetFont(buttonFont);

        // Bind events
        btn_login->Bind(wxEVT_BUTTON, &LoginFrame::OnLogin, this);
        btn_register->Bind(wxEVT_BUTTON, &LoginFrame::OnRegister, this);

        // Establish MySQL database connection
        // ... (database connection code)

        Center();
    }

private:
    wxTextCtrl* input_username;
    wxTextCtrl* input_password;

    sql::Driver* driver;
    sql::Connection* con;

    void OnLogin(wxCommandEvent& event)
    {
        wxString username = input_username->GetValue();
        wxString password = input_password->GetValue();

        // Query the database for the user credentials
        // ... (login validation code)

        // Simulate successful login
        bool loginSuccessful = true; // Replace this with your actual login validation code

        if (loginSuccessful)
        {
            wxMessageBox("Login successful!", "Login", wxOK | wxICON_INFORMATION, this);
            Close(); // Close the login frame

            // Show the home page frame
            HomePageFrame* homePageFrame = new HomePageFrame("Home Page");
            homePageFrame->Show();
        }
        else
        {
            wxMessageBox("False login!", "Login Error", wxOK | wxICON_ERROR, this);
        }
    }

    void OnRegister(wxCommandEvent& event)
    {
        // ... (user registration code)
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        LoginFrame* frame = new LoginFrame("Login");
        frame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
