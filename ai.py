from openai import OpenAI

client = OpenAI(api_key="API_Key")  # এখানে API key দাও

name = input("Enter your friend name: ")
prompt = f"""
Write a four line birthday poem for my friend {name}. 
The poem should be inspired by the first letter of my friend's name.
"""

response = client.chat.completions.create(
    model="gpt-4o-mini",
    messages=[
        {"role": "user", "content": prompt}
    ]
)

print(response.choices[0].message.content)
